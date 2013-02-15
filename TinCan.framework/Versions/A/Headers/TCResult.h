//
//  TCResult.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

typedef enum
{
    TCResultSuccessStatusNotSpecified,
    TCResultSuccessStatusFailed,
    TCResultSuccessStatusSucceeded,
} TCResultSuccessStatus;

typedef enum
{
    TCResultCompletionStatusNotSpecified,
    TCResultCompletionStatusCompleted,
} TCResultCompletionStatus;

@class TCScore;
@interface TCResult : TCObject

/**
 The score object.
 */
@property (nonatomic, strong) TCScore *score;
/**
 Whether the result represents a success or a failure. It can also be unspecified (TCResultSuccessStatusNotSpecified).
 */
@property (nonatomic, readwrite) TCResultSuccessStatus success;
/**
 Whether the result represents a completion or not. It can be unspecified (TCResultCompletionStatusNotSpecified).
 */
@property (nonatomic, readwrite) TCResultCompletionStatus completion;
/**
 A response appropriately formatted for the given activity.
 Only valid for an interaction activity. In the case of an activity of type “cmi.interaction”, this field is formatted according
 to the “cmi.interactions.n.learner_response” element defined in the SCORM 2004 4th edition Runtime Environment.
 */
@property (nonatomic, strong) NSString *response;
/**
 Period of time overwhich the statement occurred. In seconds.
 */
@property (nonatomic, readwrite) NSTimeInterval duration;
/**
 A map of other properties as needed.
 */
@property (nonatomic, strong) NSDictionary *extensions;

/**
 Initializes a result object with a score and completion/success status.
 
 @param score
 @param completion
 @param success
 */
- (id) initWithScore:(TCScore *)score completion:(TCResultCompletionStatus)completion success:(TCResultSuccessStatus)success;

/**
 Initializes a result object with a score and completion/success status.
 
 @param score
 @param completion
 @param success
 */
+ (TCResult *) resultWithScore:(TCScore *)score completion:(TCResultCompletionStatus)completion success:(TCResultSuccessStatus)success;

/**
 Initializes a result with a score.
 Success and completion are set to not specified.
 */
+ (TCResult *) resultWithScore:(TCScore *)score;
/**
 Initializes a result with a raw score. Value stored in raw property of score object.
 Success and completion are set to not specified.
 */
+ (TCResult *) resultWithRawScore:(NSNumber *)rawScore;

@end
