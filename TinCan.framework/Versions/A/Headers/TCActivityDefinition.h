//
//  TCActivityDefinition.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

typedef enum{
    TCActivityTypeNotSpecified,
    TCActivityTypeCourse,
    TCActivityTypeModule,
    TCActivityTypeMeeting,
    TCActivityTypeMedia,
    TCActivityTypePerformance,
    TCActivityTypeSimulation,
    TCActivityTypeAssessment,
    TCActivityTypeInteraction,
    TCActivityTypeCMIInteraction,
    TCActivityTypeQuestion,
    TCActivityTypeObjective,
    TCActivityTypeLink
} TCActivityType;

@class TCLanguageMap;

@interface TCActivityDefinition : TCObject

/**
 The name of the activity.
 */
@property (nonatomic, strong) TCLanguageMap *name;

/**
 A description of the activity.
 */
@property (nonatomic, strong, getter = getDescription) TCLanguageMap *description;

/**
 The type of activity.
 */
@property (nonatomic, readwrite) TCActivityType type;

/**
 Identifies a specific interaction type, in the case of an interaction activity.
 */
@property (nonatomic, strong) NSString *interactionType;

/**
 A map of any domain-specific content relative to this statement.
 Objects in extensions must be based on NSString, NSArray, or NSDictionary.
 If an object is an NSArray or NSDictionary, then the objects it contains must also be based on these classes.
 This is to support JSON encoding of the dictionary.
 
 @todo  The setter should do some basic validation to ensure that the value is okay.
 */
@property (nonatomic, strong) NSMutableDictionary *extensions;

/**
 Initializes an activity with a name, description, and type.
 
 @param aName           The name of the activity.
 @param aDescription    The description of the activity.
 @param aType           The type of activity.
 @param aExtensions     A map of domain-specific content.
 */
- (id) initWithName:(NSString *)aName description:(NSString *)aDescription type:(TCActivityType)aType extensions:(NSDictionary *)aExtensions;

/**
 Initializes an activity with a name, description, and type.
 
 @param aName           The name of the activity.
 @param aDescription    The description of the activity.
 @param aType           The type of activity.
 */
+ (TCActivityDefinition *) activityDefinitionWithName:(NSString *)aName description:(NSString *)aDescription type:(TCActivityType)aType;

/**
 Initializes an activity with a name, description, and type.
 
 @param aName           The name of the activity.
 @param aDescription    The description of the activity.
 @param aType           The type of activity.
 @param aExtensions     A map of domain-specific content.
 */
+ (TCActivityDefinition *) activityDefinitionWithName:(NSString *)aName description:(NSString *)aDescription type:(TCActivityType)aType extensions:(NSDictionary *)aExtensions;

/**
 Convenience method to add a property and value to the extensions dictionary
 without having to create a dictionary.
 
 @param value   The value to store in the extension. Must be either an NSArray, NSDictionary, or NSString.
 @param key     Store the value in this key.
 */
- (void) setExtensionPropertyValue:(id)value forKey:(NSString *)key;

/**
 Convenience method to remove a property from the extensions dictionary.
 
 @param key Removes the object at this key.
 */
- (void) removeExtensionPropertyForKey:(NSString *)key;

/**
 Sets the type property to the proper enum value that match the type described in activityType.
 */
- (void) setActivityTypeWithString:(NSString *)activityType;

@end
