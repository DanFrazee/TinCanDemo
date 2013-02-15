//
//  TCContextActivities.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import "TCObject.h"

@class TCActivity;
@interface TCContextActivities : TCObject

@property (nonatomic, strong) TCActivity *parent;
@property (nonatomic, strong) TCActivity *grouping;
@property (nonatomic, strong) TCActivity *other;

@end
