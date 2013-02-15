//
//  TCAPIActivityRequest.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAPIRequest.h>

@class TCActivity;
@protocol TCAPIActivityRequestDelegate <TCAPIRequestDelegate>
@optional
/**
 Invoked when an activity definition is retrieved from the LRS.
 */
- (void) activityRetrieved:(TCActivity *)activity;
@end

@interface TCAPIActivityRequest : TCAPIRequest

@property (nonatomic, assign) id<TCAPIActivityRequestDelegate> delegate;

/**
 @param activityId  The id of the activity to retrieve from the LRS.
 */
- (void) retrieveActivityWithActivityId:(NSString *)activityId;

@end
