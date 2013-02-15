//
//  TCContext.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCObject.h>

@class TCAgent, TCStatement, TCContextActivities;

@interface TCContext : TCObject

/**
 UUID of the registration statement is associated with.
 */
@property (nonatomic, strong) NSString *registration;
/**
 Instructor that the statement relates to, if not included as the actor or object of the statement.
 */
@property (nonatomic, strong) TCAgent *instructor;
/**
 Team that this statement relates to, if not included as the actor or object of the statement.
 */
@property (nonatomic, strong) TCAgent *team;
/**
 A map of the types of context to learning activities “activity” this statement is related to.
 Valid context types are: “parent”, “grouping”, and “other”.
 For example, if I am studying a textbook, for a test, the textbook is the activity the statement is about, but the test is a context activity, and the context type is “other”.
 {
 "other" : {"id" : "http://
 example.scorm.com/tincan/example/test" }
 }
 This activity could also be a session, like a section of a specific course, or a particular run through of a scenario. So the statement could be about “Algebra I”, but in the context of “Section 1 of Algebra I”.
 There could be an activity hierarchy to keep track of, for example “question 1” on “test 1” for the course “Algebra 1”. When recording results for “question 1”, it we can declare that the question is part of “test 1”, but also that it should be grouped with other statements about “Algebra 1”. This can be done using parent and grouping:
 {
 "parent" : {"id" : "http://
 example.scorm.com/tincan/example/test
 1" },
 "grouping" : {"id" : "http:// example.scorm.com/tincan/example/ Algebra1" }
 }
 This is particularly useful with the object of the statement is an actor, not an activity. “I mentored Ben with context Algebra I”.
 */
@property (nonatomic, strong) TCContextActivities *contextActivities;
/**
 Revision of the learning activity associated with this statement.
 Revisions are to track fixes of minor issues (like a spelling error), if there is any substantive change to the learning objectives, pedagogy, or assets associated with an activity, a new activity ID should be used.
 Revision format is up to the owner of the associated activity. Not applicable if statement's object is a Person.
 */
@property (nonatomic, strong) id revision;
/**
 Platform used in the experience of this learning activity. Not applicable if statement's object is a Person. Defined vocabulary, TBD.
 */
@property (nonatomic, strong) NSString *platform;
/**
 Code representing the language in which the experience being recorded in this statement (mainly) occurred in, if applicable and known. Do not specify any value if not applicable or not known.
 Format for this value is as defined in RFC3066.
 For example, US English would be recorded as: en-US
 */
@property (nonatomic, strong) NSString *language;
/**
 Another statement (either existing or new), which should be considered as context for this statement. This could be used to add context to a comment, or when grading.
 */
@property (nonatomic, strong) TCStatement *statement;
/**
 A map of any other domain-specific context relevant to this statement. For example, in a flight simulator altitude, airspeed, wind, attitude, GPS coordinates might all be relevant.
 */
@property (nonatomic, strong) NSMutableDictionary *extensions;

/**
 Returns an autoreleased blank context object.
 */
+ (TCContext *) context;

@end
