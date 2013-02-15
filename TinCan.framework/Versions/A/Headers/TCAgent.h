//
//  TCAgent.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCStatementObject.h>

@class TCAccount;

/**
 An "agent" may refer to an indiviual learner or a team of learners.
 
 @remarks   Note that all properties are arrays. The most correct, or most recent data should be listed first in each array.
 */
@interface TCAgent : TCStatementObject

/**
 An array of known names for this agent.
 */
@property (nonatomic, strong) NSMutableArray *name;

/**
 An array of e-mail addresses that have only ever been assigned to this agent.
 */
@property (nonatomic, strong) NSMutableArray *mbox;

/**
 An array of SHA1 hashed e-mail addresses that have only ever been assigned to this agent. 
 The LRS will compare this value with mbox values by applying SHA1(mbox).
 */
@property (nonatomic, readonly) NSArray *mbox_sha1sum;

/**
 An array of URIs associated with an openID for this agent.
 */
@property (nonatomic, strong) NSMutableArray *openid;

/**
 An array of account objects associated with this agent.
 You can conveniently add account information by calling -addAccountWithID:serviceHomePage:.
 */
@property (nonatomic, strong) NSMutableArray *account;

/**
 Initializes an agent with a name and an e-mail address.
 */
- (id) initWithName:(NSString *)aName andMbox:(NSString *)aMbox;

/**
 Convenience method for creating an agent with a name and e-mail address.
 
 @param aName   The name of the agent.
 @param aMbox   The email address (in mailto:{email}) form.
 */
+ (TCAgent *) agentWithName:(NSString *)aName andMbox:(NSString *)aMbox;

/**
 Adds account information for an account with the specified account ID and service home page.
 
 @param accountName     The unique ID or username for the account.
 @param serviceHomePage The canonical home page for the service (e.g. http://twitter.com/).
 */
- (void) addAccountWithID:(NSString *)accountName forService:(NSString *)serviceHomePage;

/**
 Adds an e-mail address to the agent.
 Automatically prepends the address with the mailto: scheme if it doesn't already exist.
 
 @param emailAddress    The e-mail address to associate with the user.
 */
- (void) addEmailAddress:(NSString *)emailAddress;

@end
