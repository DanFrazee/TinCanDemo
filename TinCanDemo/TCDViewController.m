//
//  TCDViewController.m
//  TinCanDemo
//
//  Created by Dan Frazee on 11/13/12.
//  Copyright (c) 2012 Maestro. All rights reserved.
//

#import "TCDViewController.h"
#import <AddressBook/AddressBook.h>

@interface TCDViewController ()

@end

@implementation TCDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
        
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(TCErrorRecieved:) name:TCStatementsFailedPersistingNotification object:nil];

    [self generateStatement];

    
    [[TCAPI defaultAPI] getStatementWithQuery:[TCStatementQuery statementQueryWithLimit:10] delegate:self];
};

- (void)statementsReceived:(TCStatementsResult *)result
{
    NSLog(@"%d statements received.", result.numberOfStatements);
    NSLog(@"Statements: %@", result.statements);
}

- (void)TCErrorRecieved:(NSNotification *)notification
{
    NSLog(@"%@",notification.userInfo);
}

- (void)generateStatement{
    NSDictionary *dict = @{     @"objectType" : @"Activity",
                                        @"id" : @"http://meetmaestro.com/tincan/example/course",
                                 @"definition": @{           @"name" :    [TCLanguageMap languageMapForCurrentLanguageWithString:@"How to be a Millionare"].map,
                                                      @"description" :    [TCLanguageMap languageMapForCurrentLanguageWithString:@"A simple lesson on 'How to be a Millionare'"].map
                                                    }
                            };
    
    TCStatementObject *stobject = [TCStatementObject objectFromDictionary:dict];
    TCStatement *statement = [TCStatement statementWithActor:[TCAgent agentWithName:@"William" andMbox:@"mailto:william@gmail.com"] statementVerb:TCStatementVerbAttempted andObject:stobject];
    [statement setSid:[TCStatement generateUUID]];    
}

- (IBAction)selectContact:(id)sender{
    __block NSString *email;
    
    ABAddressBookRef addressBook = ABAddressBookCreateWithOptions(NULL, NULL);
    
    ABAddressBookRequestAccessWithCompletion(addressBook, ^(bool granted, CFErrorRef error) {
        if (!granted)
            return;
        
        //Creates an NSArray from the CFArrayRef using toll-free bridging
        NSArray *arrayOfPeople = (__bridge_transfer NSArray *)ABAddressBookCopyArrayOfAllPeople(addressBook);
        
        CFRelease(addressBook);
        
        if (arrayOfPeople.count == 0) {
            return;
        }
        
        ABRecordRef currentPerson = (__bridge ABRecordRef)[arrayOfPeople objectAtIndex:0];
        
        ABMultiValueRef emailsMultiValueRef = ABRecordCopyValue(currentPerson, kABPersonEmailProperty);
        
        NSUInteger emailsCount;
        //Goes through the emails to check which one is the home email
        for(emailsCount = 0; emailsCount <= ABMultiValueGetCount(emailsMultiValueRef);emailsCount++){
            NSString *emailLabel = (__bridge_transfer NSString *)ABMultiValueCopyLabelAtIndex (emailsMultiValueRef, emailsCount);
            
            if([emailLabel isEqualToString:@"Home"]){
                
                if ((__bridge_transfer NSString *)ABMultiValueCopyValueAtIndex(emailsMultiValueRef, emailsCount) != NULL){
                    
                    email = (__bridge_transfer NSString *)ABRecordCopyValue(currentPerson, kABPersonEmailProperty);
                }
                
                //If the last name property does not exist
                else{
                    
                    email = @"NULL";
                }
            }
        }
        
        NSLog(@"%@",email);
    });
}


@end
