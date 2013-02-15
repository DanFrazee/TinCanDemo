//
//  TCBasicHTTPAuthentication.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>
#import <TinCan/TCAPIRequest.h>

/**
 Implements the HTTP Basic authentication specification for adding an Authorization header to a TCAPIRequest.
 */
@interface TCBasicHTTPAuthentication : NSObject <TCAPIAuthenticationProvider>

/**
 The user name to use for basic authorization.
 */
@property (nonatomic, strong) NSString *username;

/**
 The password to use for basic authorization.
 */
@property (nonatomic, strong) NSString *password;

/**
 The generated header value for Authorization.
 This value is generated from the values in username and password.
 To directly assign an authHeaderValue, use -manuallySetAuthorizationHeaderValue:.
 */
@property (nonatomic, strong) NSString *authHeaderValue;

/**
 Initializes the HTTP authentication with a username and password.
 
 @param aUsername   The username.
 @param aPassword   The password.
 */
- (id) initWithUsername:(NSString *)aUsername andPassword:(NSString *)aPassword;

/**
 Manually sets the authoriziation header value.
 The values in username and password will be ignored in favor of using
 the manually specified authorization header value.
 No validation occurs on this value. It is your responsibility to ensure that it is valid.
 
 @param authHeaderValue  The value to assign to the authorization header before sending a request to the LRS.
 */
- (void) manuallySetAuthorizationHeaderValue:(NSString *)authHeaderValue;

@end
