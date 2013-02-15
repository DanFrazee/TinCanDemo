//
//  TCStatementQueue.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>
#import <TinCan/TCStatementQueuePersisting.h>

@class TCStatement;

/**
 The queue for statements to wait in before being sent to the LRS.
 Statements that are to be stored on the LRS enter into a queue that is flushed on a specified time interval.
 */
@interface TCStatementQueue : NSObject

/**
 The statements that are currently queued for sending to the LRS.
 The statements are ordered oldest to newest (first to last).
 This contains ALL statements in the queue--even statements that have already
 been sent to the LRS and are waiting to determine if they were successfully persisted.
 It will (potentially) still contain a statement that has already been successfully pesisted
 that hasn't been removed from the queue yet. These will be removed the next time the queue is sent to the LRS.
 */
@property (nonatomic, strong, readonly) NSMutableArray *queuedStatements;

/**
 Coordinator responsible for local persistence of statements in this queue.
 */
@property (nonatomic, strong) id<TCStatementQueuePersisting> persistenceCoordinator;

/**
 An array of statements in the queue that have not been sent to the LRS for persistence.
 The TCAPI statement posting interval uses this value to POST batches of statements to the LRS.
 This is a (potentially) expensive operation as it will iterate through every statement in the
 queue and check whether it still needs to be persisted.
 */
@property (nonatomic, readonly) NSArray *unsentStatements;

/**
 YES if there are statements in the queue waiting to go to the LRS.
 */
@property (nonatomic, readonly) BOOL hasQueuedStatements;

/**
 Number of statements in the queue REGARDLESS of whether they are currently
 attempting to be persisted to the LRS.
 To check the number of statements that need to be persisted, check the size of the
 array in statementsToPersist.
 */
@property (nonatomic, readonly) NSUInteger numberOfQueuedStatements;

/**
 Add multiple statements to the statement queue.
 The statements are added to the end of the statement queue.
 Any statements that have already been persisted to the LRS (as interally determined) will be ignored.
 
 @param statements An array of statements to merge into the statement queue.
 */
- (void) addStatements:(NSArray *)statements;

/**
 Adds a single statement to the statement queue.
 The statement gets added to the end of the statement queue.
 If the statement has already been persisted to the LRS, this method will do nothing.
 
 @param statement The statement to add to the end of the queue.
 */
- (void) addStatement:(TCStatement *)statement;

/**
 Retrieves statements from the front of the queue.
 
 @param count   The number of statements to retrieve. If count is greater than the number of statements in the queue, then all the statements are retrieved.
 @return        An array of queued statements ordered by oldest to newest queued.
 */
- (NSArray *) getQueuedStatements:(int)count;

/**
 Retrieves statements from the of the queue starting at a specified index.
 
 @param count   The number of statements to retrieve. If count is greater than the number of statements in the queue, then all the statements are retrieved.
 @param index   The index to start at.
 @return        An array of queued statements ordered by oldest to newest queued.
 */
- (NSArray *) getQueuedStatements:(int)count startingAtIndex:(NSUInteger)index;

/**
 The statements that are queued for sending to the LRS.
 
 @return An array of queued statements. Ordered by oldest to newest queued statement.
 */
- (NSArray *) getQueuedStatements;

/**
 Removes a statement from the queue (if it exists). This method does nothing if the statement doesn't exist in the LRS.
 
 @param statement   The statement to remove from the queue.
 */
- (void) removeStatement:(TCStatement *)statement;

/**
 Removes all statements from the queue.
 */
- (void) removeAllStatements;

/**
 Remove all the statements in the queue that are also contained in the supplied array.
 
 @param statementsToRemove  The statements to remove from the statement queue.
 */
- (void) removeStatementsInArray:(NSArray *)statementsToRemove;

/**
 Persists the current state of the queue.
 */
- (void) persistToLocalStore;

/**
 The default statement queue.
 */
+ (TCStatementQueue *) defaultStatementQueue;

@end
