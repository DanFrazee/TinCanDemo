//
//  TCActorProfile.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCState.h>

@class TCAgent;
@interface TCActorProfile : TCState

@property (nonatomic, strong) TCAgent *actor;
@property (nonatomic, strong) NSString *profileId;

- (id) initWithActor:(TCAgent *)actor andProfileId:(NSString *)profileId;
+ (TCActorProfile *) actorProfileWithActor:(TCAgent *)actor andProfileId:(NSString *)profileId;

@end
