//
//  TCInteractionDefinition.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import "TCActivityDefinition.h"

@interface TCInteractionDefinition : TCActivityDefinition

@property (nonatomic, strong) NSArray *correctResponsesPattern;
@property (nonatomic, strong) NSArray *choices;
@property (nonatomic, strong) NSArray *scale;
@property (nonatomic, strong) NSArray *source;
@property (nonatomic, strong) NSArray *target;
@property (nonatomic, strong) NSArray *steps;

@end
