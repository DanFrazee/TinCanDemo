//
//  TCAPIActivityStateRequest.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAPIRequest.h>

@class TCActivityState, TCAgent;
@protocol TCAPIActivityStateRequestDelegate <TCAPIRequestDelegate>

@optional
/**
 Invoked when the activity state was saved succesfully.
 */
- (void) activityStateSaved:(TCActivityState *)state;
/**
 Invoked when an activity state was retrieved from the server.
 */
- (void) activityStateRetrieved:(TCActivityState *)state;
/**
 Invoked when an activity state is deleted from the LRS.
 */
- (void) activityStateDeleted:(TCActivityState *)state;
/**
 Invoked when multiple activities are deleted from the LRS.
 */
- (void) activityStatesDeleted:(NSArray *)activityStateIDs;
/**
 Invoked when multiple activity ids are retrieved from the LRS.
 */
- (void) activityStateIDsRetrieved:(NSArray *)activityStateIDs;

@end

@interface TCAPIActivityStateRequest : TCAPIRequest

@property (nonatomic, assign) id<TCAPIActivityStateRequestDelegate> delegate;

/**
 @param state       The activity state to save to the LRS. The activity state must have a stateId, activityId, and actor defined.
 */
- (void) saveActivityState:(TCActivityState *)state;
/**
 @param state               The activity state to save to the LRS. The activity state must have a stateId, activityId, and actor defined.
 @param shouldOverwrite     Set to YES to tell the server to overwrite any pre-existing activity states, regardless of when they were created.
                            Set to NO to have the request fail if there is the activity state already exists on the server and (may) have been
                            changed since the last time your application downloaded it.
 @param previousState       The most recent activity state your application is aware of. This activity state must have been received from any
                            one of the getActivityState... methods.
 */
- (void) saveActivityState:(TCActivityState *)state overwriting:(BOOL)shouldOverwrite previousState:(TCActivityState *)previousState;
/**
 @param activityId      The id of the activity--must not be empty.
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param stateId         The specific id of the activity state you want to retrieve--must not be empty.
 @param registrationId  Make the search for an activity state more specific by specifying a registration id.
 */
- (void) getActivityStateWithActivityId:(NSString *)activityId actor:(TCAgent *)actor andStateId:(NSString *)stateId registrationId:(NSString *)registrationId;
/**
 @param activityId      The id of the activity--must not be empty
 @param actor           Only fetch activity states relating to this actor--must contain atleast one identifiying propetty (e.g. an email address).
 @param since           Only fetch activity states created/updated after this date/time.
 @param registrationId  Make the search for an activity state more specific by specifying a registration id.
 */
- (void) getActivityStateIdsWithActivityId:(NSString *)activityId forActor:(TCAgent *)actor registrationId:(NSString *)registrationId since:(NSDate *)since;
/**
 @param activityId      The id of the activity--must not be empty.
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param stateId         The specific id of the activity state you want to retrieve--must not be empty.
 @param registrationId  Only delete activity state if the registration id matches.
 */
- (void) deleteActivityStateWithActivityId:(NSString *)activityId actor:(TCAgent *)actor andStateId:(NSString *)stateId registrationId:(NSString *)registrationId;
/**
 @param activityId      The id of the activity--must not be empty.
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param registrationId  Only delete activity state if the registration id matches.
 */
- (void) deleteAllActivityStatesWithActivityId:(NSString *)activityId actor:(TCAgent *)actor registrationId:(NSString *)registrationId;

@end