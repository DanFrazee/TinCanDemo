//
//  TCGroup.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAgent.h>

@interface TCGroup : TCAgent

/**
 (array of) Agent objects representing members of this group.
 */
@property (nonatomic, strong) NSMutableArray *members;

@end
