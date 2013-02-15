//
//  TCActivityState.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCState.h>

@class TCAgent, TCActivity;
@interface TCActivityState : TCState

@property (nonatomic, strong) NSString *activityId;
@property (nonatomic, strong) TCAgent *actor;
@property (nonatomic, strong) NSString *registrationId;

- (id) initWithStateId:(NSString *)stateId activityId:(NSString *)activityId andActor:(TCAgent *)actor;
+ (TCActivityState *) stateForActivity:(TCActivity *)activity forActor:(TCAgent *)actor; // automatically generates state id
+ (TCActivityState *) activityStateWithActivityId:(NSString *)activityId andActor:(TCAgent *)actor;
+ (TCActivityState *) stateWithID:(NSString *)stateId forActivity:(TCActivity *)activity forActor:(TCAgent *)actor;
+ (TCActivityState *) stateWithID:(NSString *)stateId forActivityId:(NSString *)activityId forActor:(TCAgent *)actor;

@end
