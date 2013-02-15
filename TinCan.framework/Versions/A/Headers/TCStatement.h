//
//  TCStatement.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCStatementObject.h>

extern NSString* const kTCStatementId;
extern NSString* const kTCStatementActor;
extern NSString* const kTCStatementVerb;
extern NSString* const kTCStatementInProgress;
extern NSString* const kTCStatementObject;
extern NSString* const kTCStatementResult;
extern NSString* const kTCStatementContext;
extern NSString* const kTCStatementTimestamp;
extern NSString* const kTCStatementAuthority;
extern NSString* const kTCStatementVoided;

/**
 Represents the statement verbs recognized by the Tin Can LRS 
 (based on the 0.9 version of the API specification).
 */
typedef enum{
    TCStatementVerbExperienced,
    TCStatementVerbAttended,
    TCStatementVerbAttempted,
    TCStatementVerbCompleted,
    TCStatementVerbPassed,
    TCStatementVerbFailed,
    TCStatementVerbAnswered,
    TCStatementVerbInteracted,
    TCStatementVerbImported,
    TCStatementVerbCreated,
    TCStatementVerbShared,
    TCStatementVerbVoided
} TCStatementVerb;

@class TCAgent, TCResult, TCContext;

/**
 Represents a Tin Can statement to be sent to the API.
 A simple statement consisting of [Actor (learner)] [verb] [object], with [result], in [context] 
 to track an aspect of a learning experience. A set of several statements may be used to track complete details about a learning experience.
 */
@interface TCStatement : TCStatementObject

/**
 The ID for the statement. May be assigned by the statement creator or the LRS.
 */
@property (nonatomic, strong) NSString *sid;

/**
 Learner or Team object the statement is about (the "I" in the statement). 
 If not specified, LRS will infer based on authentication, and populate the actor.
 */
@property (nonatomic, retain) TCAgent *actor;

/**
 The "verb" portion of the statement.
 */
@property (nonatomic, strong) NSString *verb;

/**
 Indicates whether the LRS should wait for further information about this statement.
 (e.g. Is this statement just a mention of a learning experience in progress, but not yet submitted.
 */
@property (nonatomic) BOOL inProgress;

/**
 Activity, agent, or another statement that is the object of the statement (the "this" portion).
 */
@property (nonatomic, retain) TCStatementObject *object;

/**
 More details relevant to the specified verb.
 */
@property (nonatomic, strong) TCResult *result;

/**
 Context that gives the statement more meaning.
 */
@property (nonatomic, strong) TCContext *context;

/**
 The timestamp of when what this statement describes happened.
 */
@property (nonatomic, strong) NSDate *timestamp;

/**
 Timestamp of when the statement was recorded (set by the LRS).
 */
@property (nonatomic, readonly) NSDate *stored;

/**
 Actor who is asserting this statement is true. Verified by the LRS based on authentication
 and set by the LRS if authority is left blank.
 */
@property (nonatomic, strong) TCAgent *authority;

/**
 Indicates that the statement has been voided.
 */
@property (nonatomic) BOOL voided;

/**
 YES if this statement can be voided; NO otherwise.
 Only statements that have not been voided and are not voiding statements can be voided.
 */
@property (nonatomic, readonly) BOOL canBeVoided;


/**
 Instantiates a statement with an actor, verb, and object.
 
 @param aActor  The TCAgent to use as the actor for the statement.
 @param aVerb   The TCStatementVerb that indicates what happened.
 @param aObject The object of the statement.
 @return        The initalized statement.
 */
- (id) initWithActor:(TCAgent *)aActor statementVerb:(TCStatementVerb)aVerb andObject:(TCStatementObject *)aObject;

/**
 Instantiates a statement with a verb and object.
 When this verb is stored in the queue, the actor is assigned to the defaultActor on TCAPI.
 
 @param aVerb   The TCStatementVerb that indicates what happened.
 @param aObject The object of the statement.
 @return        The initalized statement.
 @remarks    Calls +statementWithActor:statementVerb:andObject: with actor set to nil.
 */
+ (TCStatement *) statementWithVerb:(TCStatementVerb)aVerb andObject:(TCStatementObject *)aObject;

/**
 Instantiates a statement with an actor, verb, and object.
 
 @param aActor  The TCAgent to use as the actor for the statement.
 @param aVerb   The TCStatementVerb that indicates what happened.
 @param aObject The object of the statement.
 @return        The initalized statement.
 */
+ (TCStatement *) statementWithActor:(TCAgent *)aActor statementVerb:(TCStatementVerb)aVerb andObject:(TCStatementObject *)aObject;

/**
 Generates a unique ID for the statement.
 */
+ (NSString *) generateUUID;

/**
 Generates a voiding statement for this statement.
 The voiding statement is a new statement with the verb set to "voided", the object set to the current statement (just the ID and statement type),
 and the actor set to the specified actor.
 
 @param aActor  The actor that is voiding the statement. If set to nil, it will use the actor of the original statement as the actor of the voiding statement.
 @return        A new voiding statement for this statement. This statement must be persisted on the LRS for the voiding to actually take place.
                It will return nil if the statement cannot be voided.
 */
- (TCStatement *) generateVoidingStatementWithActor:(TCAgent *)aActor;

@end
