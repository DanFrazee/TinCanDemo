//
//  TCObject.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

extern NSString* const kObjectType;

@interface TCObject : NSObject

- (void) setTinCanValue:(id)value forProperty:(NSString *)key;
- (NSDictionary *) propertyMapping;
- (id) initWithDictionary:(NSDictionary *)dict;
+ (id) objectFromDictionary:(NSDictionary *)dict;
- (id) tinCanValueForKey:(NSString *)key;
/**
 Returns an array of all the class properties that should be included when converting the class to a dictionary.
 The default implementation of this method iterates through all the properties of the class and its superclasses (until NSObject).
 Subclasses may explicitly define what properties can be retrieved by overriding this method and returning an NSArray.
 
 @return    An array of NSString objects that represent the property names to add to the dictionary representation of the class.
 */
- (NSArray *) classProperties;

/**
 Retrieves a dictionary reprsentation of this Tin Can object.
 */
- (NSDictionary *) dictionary;

/**
 Converts this object to a JSON string compatible with the Tin Can API.
 */
- (NSString *) JSONString;

/**
 Same as JSONString but the output is formatted nicely (suitable for on-screen display).
 */
- (NSString *) prettyJSONString;

/**
 Same as JSONString, but it represents the bytes of the string.
 */
- (NSData *) JSONData;


@end
