//
//  TCStatementObject.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

/**
 Parent class for objects that are eligible to be the object property on a statement.
 */
@interface TCStatementObject : TCObject

@property (nonatomic, strong) NSString *objectType;

@end
