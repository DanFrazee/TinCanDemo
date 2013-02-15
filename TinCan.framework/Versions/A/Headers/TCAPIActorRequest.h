//
//  TCAPIActorRequest.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAPIRequest.h>

@class TCAgent;

@protocol TCAPIActorRequestDelegate <TCAPIRequestDelegate>
@optional
/**
 Invoked when a full actor object is retrieved from the LRS.
 */
- (void) actorRetrieved:(TCAgent *)actor;
@end

@interface TCAPIActorRequest : TCAPIRequest

@property (nonatomic, assign) id<TCAPIActorRequestDelegate> delegate;

/**
 Retrieves everything the LRS knows about an actor that has identifying propeties that match the supplied actor.
 @param actor   The actor to find on the LRS.
 */
- (void) retrieveActorWithPartialActor:(TCAgent *)actor;

@end
