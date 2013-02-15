//
//  TCAccount.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

/**
 Represents an account owned by a user.
 
 @remarks   If the agent is authenticated via the OAuth Reigstered application workflow (with no known user),
            then the consumer_key should be used as the accountName, and the token request endpoint should
            be used as the accountServiceHomePage. <strong>It is crucial not to do this for any agent object
            where a known user is involved, as this would lead to logically different agents being considered
            identical by the LRS.</strong>
 */
@interface TCAccount : TCObject

/**
 The URI to the canonical home page for the system the account is on. Must NOT be nil or empty string.
 */
@property (nonatomic, strong) NSString *accountServiceHomePage;

/**
 The unique ID or name used to log in to this account. Must NOT be nil or empty string.
 */
@property (nonatomic, strong) NSString *accountName;

/**
 Creates a new account reference specifying the account name and service homepage.
 
 @param aServiceHomePage    The URI to the canonical home page for the system the account is on (e.g http://twitter.com).
 @param aAccountName        The unique ID or name used to log in to this account.
 @return                    The initialized account object.
 */
- (id) initWithServiceHomePage:(NSString *)aServiceHomePage andAccountName:(NSString *)aAccountName;

/**
 Creates a new account reference specifying the account name and service homepage.
 
 @param aAccountName        The unique ID or name used to log in to this account.
 @param aServiceHomePage    The URI to the canonical home page for the system the account is on (e.g http://twitter.com).
 @return                    The initialized account object.
 */
+ (TCAccount *) accountWithID:(NSString *)aAccountName forServiceHomePage:(NSString *)aServiceHomePage;

@end
