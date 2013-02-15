//
//  TCScore.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

@interface TCScore : TCObject

/**
 cmi.score.scaled (recommended)
 */
@property (nonatomic, strong) NSNumber *scaled;
/**
 cmi.score.raw
 */
@property (nonatomic, strong) NSNumber *raw;
/**
 cmi.score.min
 */
@property (nonatomic, strong) NSNumber *min;
/**
 cmi.score.max
 */
@property (nonatomic, strong) NSNumber *max;

/**
 Initializes a score.
 */
- (id) initWithRawScore:(NSNumber *)raw minimumScore:(NSNumber *)min maximumScore:(NSNumber *)max scaledScore:(NSNumber *)scaled;

/**
 Intializes a score with just a raw score.
 The other properties are not specified.
 
 @param raw     The raw score.
 */
+ (TCScore *) scoreWithRawScore:(NSNumber *)raw;

@end
