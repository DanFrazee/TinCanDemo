//
//  TinCan.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

/**
 @mainpage
 About Tin Can
 =============
 SCORM is over 10 years old. ADL, the keepers of SCORM, tasked us with researching what the next-generation e-learning specification could/should look like. 
 
 The Tin Can API solves a lot of problems that older specifications suffered from, but it also adds many new capabilities. The Tin Can API fuses a decade of collective e-learning experiences with a decade of technological advances.
 
 The Tin Can Objective-C Library for iOS is (c) 2012 [Float Mobile Learning](http://floatlearning.com).
 Project assistance provided by the Rustici team.
 */


// SDK Information
#define TINCANSDK_VERSION   @"0.9";
// Debugger
// To enable debug messages from the TinCanSDK, simply call TCEnableLogging() anywhere in your code.
// To disable debugging, call TCDisableLogging().
// Logging will NOT be enabled if __OPTIMIZE__ is defined. __OPTIMIZE__ is defined, by default, on release builds of your application.
BOOL TCShouldLogDebugMessages;
#ifndef __OPTIMIZE__
#define TCEnableLogging()  {TCShouldLogDebugMessages = YES;}
#else
#define TCEnableLogging()  {TCShouldLogDebugMessages = NO;}
#endif
#define TCDisableLogging() {TCShouldLogDebugMessages = NO;}

// API Interaction
#import <TinCan/TCAPI.h>
#import <TinCan/TCBasicHTTPAuthentication.h>
#import <TinCan/TCStatementQueue.h>
#import <TinCan/TCStatementQueueFilePersistence.h>

// Extended Types
#import <TinCan/TCActivityProfile.h>
#import <TinCan/TCActivityState.h>
#import <TinCan/TCActorProfile.h>
#import <TinCan/TCContextActivities.h>
#import <TinCan/TCInteraction.h>
#import <TinCan/TCInteractionComponents.h>
#import <TinCan/TCInteractionDefinition.h>
#import <TinCan/TCStatementQuery.h>

// Standard Types
#import <TinCan/TCAccount.h>
#import <TinCan/TCActivity.h>
#import <TinCan/TCActivityDefinition.h>
#import <TinCan/TCAgent.h>
#import <TinCan/TCContext.h>
#import <TinCan/TCGroup.h>
#import <TinCan/TCLanguageMap.h>
#import <TinCan/TCObject.h>
#import <TinCan/TCPerson.h>
#import <TinCan/TCResult.h>
#import <TinCan/TCScore.h>
#import <TinCan/TCState.h>
#import <TinCan/TCStatement.h>
#import <TinCan/TCStatementObject.h>
#import <TinCan/TCStatementsResult.h>

