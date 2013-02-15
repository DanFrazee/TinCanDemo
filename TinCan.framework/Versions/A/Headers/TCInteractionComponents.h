//
//  TCInteractionComponents.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

@class TCLanguageMap;
@interface TCInteractionComponents : NSObject

@property (nonatomic, strong) NSString *componentId;
@property (nonatomic, strong, getter=getDescription) TCLanguageMap *description;

@end
