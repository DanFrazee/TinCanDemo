//
//  TCLanguageMap.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

/**
 Strings within TinCan are localized using a language map.
 The language map contains a string for a language tag.
 
 The language tag should be a string that conforms to the RFC 5646 Language Tag specification.
 http://tools.ietf.org/html/rfc5646
 */
@interface TCLanguageMap : TCObject
{
    @private
    /**
     The TCLanguageMap is really just a map for an NSDictionary to require
     that both the key and values are strings.
     In the future, it *may* attempt to validate language tags.
     */
    NSMutableDictionary *languageMap;
}

/**
 Returns the string for the first specified language tag.
 */
@property (nonatomic, readonly) NSString *string;

/**
 An array of the language tags defined in this language map.
 */
@property (nonatomic, readonly) NSArray *languageTags;

/**
 The raw NSDictionary language map.
 */
@property (nonatomic, readonly) NSDictionary *map;

/**
 Creates a language map initialized with the specified string for the specified language tag.
 
 @param aLanguageTag    The language tag to use to initialize the language map.
 @param aString         The string value to assign to the language tag.
 @return                The initialized language map.
 */
- (id) initWithLanguageTag:(NSString *)aLanguageTag andString:(NSString *)aString;

/**
 Creates a language map assigning the specified string with a language tag
 compatible with the current device locale.
 
 @param aString The string to use to initialize the language tag for the current locale.
 @return        The initialized language map.
 */
+ (TCLanguageMap *) languageMapForCurrentLanguageWithString:(NSString *)aString;

/**
 Creates a language map from a dictionary.
 */
+ (TCLanguageMap *) languageMapWithDictionary:(NSDictionary *)dict;

/**
 Assigns a string to a language tag and adds it to the language map.
 
 @param aString         The string to add to the language map.
 @param aLanguageTag    The language tag to set the value of.
 */
- (void) setString:(NSString *)aString forLanguageTag:(NSString *)aLanguageTag;

/**
 Removes the string assigned to the specified language tag.
 */
- (void) removeLangaugeTag:(NSString *)aLanguageTag;

/**
 Retrieves the string value for a language tag.
 
 @param aLanguageTag    The language tag from which to return the string value.
 @return                The string value for the specified language tag. Returns nil if the language tag didn't exist.
 */
- (NSString *) stringForLanguageTag:(NSString *)aLanguageTag;

@end
