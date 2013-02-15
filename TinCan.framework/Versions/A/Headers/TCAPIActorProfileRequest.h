//
//  TCAPIActorProfileRequest.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAPIRequest.h>

@class TCActorProfile, TCAgent;
@protocol TCAPIActorProfileRequestDelegate <TCAPIRequestDelegate>
@optional
/**
 Invoked when an actor profile is retrieved from the LRS.
 */
- (void) actorProfileRetrieved:(TCActorProfile *)profile;
/**
 Invoked when an actor profile is saved to the LRS.
 */
- (void) actorProfileSaved:(TCActorProfile *)profile;
/**
 Invoked when an actor profile is deleted from the LRS.
 */
- (void) actorProfileDeleted:(TCActorProfile *)profile;
/**
 Invoked when multiple profile ids are retrieved from the LRS.
 */
- (void) actorProfileIdsRetrieved:(NSArray *)profileIds;
/**
 Invoked when multiple profiles are deleted for an actor.
 */
- (void) actorProfilesDeleted;

@end

@interface TCAPIActorProfileRequest : TCAPIRequest

@property (nonatomic, assign) id<TCAPIActorProfileRequestDelegate> delegate;

/**
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param profileId       The specific if of the actor profile you want to retrieve--must not be empty.
 */
- (void) retrieveActorProfileForActor:(TCAgent *)actor andProfileId:(NSString *)profileId;
/**
 @param profile         The actor profile to save to the LRS. The actor profile must have a profileId and actor defined.
 */
- (void) saveActorProfile:(TCActorProfile *)profile;
/**
 @param profile         The actor profile to save to the LRS. The actor profile must have a profileId and actor defined.
 @param shouldOverwrite Set to YES to tell the server to overwrite any pre-existing actor profiles, regardless of when they were created.
                        Set to NO to have the request fail if there is the actor profile already exists on the server and (may) have been
                        changed since the last time your application downloaded it.
 @param previousProfile The most recent actor profile your application is aware of. This actor profile must have been received from any
                        one of the getActorProfile... methods.
 */
- (void) saveActorProfile:(TCActorProfile *)profile overwriting:(BOOL)shouldOverwrite previousProfile:(TCActorProfile *)previousProfile;
/**
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param profileId       The specific if of the actor profile you want to retrieve--must not be empty.
 */
- (void) deleteActorProfileForActor:(TCAgent *)actor andProfileId:(NSString *)profileId;
/**
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 */
- (void) deleteAllActorProfilesForActor:(TCAgent *)actor;
/**
 @param actor           The actor object--this must contain atleast one identifying property (e.g. an email address).
 @param since           Only fetch actor profiles created/updated after this date/time.
 */
- (void) retrieveActorProfileIdsForActor:(TCAgent *)actor since:(NSDate *)since;

@end
