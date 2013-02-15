//
//  TCActivity.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCStatementObject.h>

@class TCActivityDefinition;

/**
 A unit of instruction, experience, or performance that is to be tracks.
 */
@interface TCActivity : TCStatementObject

/**
 The URL or URI that uniquely identifies the activity.
 The id must always refer to a single unique activity.
 */
@property (nonatomic, strong) NSString *activityId;

/**
 Meta data about the activity.
 */
@property (nonatomic, strong) TCActivityDefinition *definition;

/**
 Initializes the activity with an id and definition.
 
 @param aActivityId The activity ID.
 @param aDefinition The activity definition.
 */
- (id) initWithID:(NSString *)aActivityId andDefinition:(TCActivityDefinition *)aDefinition;

+ (TCActivity *) activityWithId:(NSString *)activityId;

/**
 Initializes the activity with an id and definition.
 
 @param aActivityID The activity ID.
 @param aDefinition The activity definition.
 */
+ (TCActivity *) activityWithID:(NSString *)aActivityID andDefinition:(TCActivityDefinition *)aDefinition;

@end
