//
//  TCState.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

@interface TCState : TCObject

/**
 Required. The stateId serves as the key for whatever is stored on the LRS.
 This must be set before sending to the LRS.
 */
@property (nonatomic, strong) NSString *stateId;
@property (nonatomic, strong) NSData *contents;
@property (nonatomic, strong) NSDate *updated;
@property (nonatomic, strong) NSString *contentType;

// Convenient ways to set string/dictionary
@property (nonatomic, strong) NSString *stringContents;
@property (nonatomic, strong) NSDictionary *dictionaryContents;

- (id) initWithStateId:(NSString *)stateId;

@end
