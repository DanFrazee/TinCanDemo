//
//  TCInteraction.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import "TCActivity.h"
#import "TCInteractionDefinition.h"

@interface TCInteraction : TCActivity

@property (nonatomic, strong) TCInteractionDefinition *definition;

@end
