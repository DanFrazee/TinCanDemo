//
//  TCActivityProfile.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCState.h>

@class TCActivity;
@interface TCActivityProfile : TCState

@property (nonatomic, strong) NSString *activityId;
@property (nonatomic, strong) NSString *profileId; //Just a map to stateId

- (id) initWithActivityId:(NSString *)activityId andProfileId:(NSString *)profileId;
+ (TCActivityProfile *) activityProfileForActivity:(TCActivity *)activity;
+ (TCActivityProfile *) activityProfileForActivity:(TCActivity *)activity andProfileId:(NSString *)profileId;
+ (TCActivityProfile *) activityProfileForActivityId:(NSString *)activityId andProfileId:(NSString *)profileId;

@end
