//
//  TCStatementQueuePersisting.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

@protocol TCStatementQueuePersisting <NSObject>

// Persist statement queue
/**
 Invoked by the statement queue when it wants to save the current state of the queue.
 
 @param statements  The statements to store.
 @param error       Return any error encountered while persisting the store.
 @returns           YES if the statements were stored successfully.
 */
- (BOOL) persistStatements:(NSArray *)statements withError:(NSError **)error;

/**
 Checked by the statement queue during application start up. Determines if it needs to restore statements in the queue to memory.
 */
- (BOOL) needsToRestoreQueue;

/**
 If needsToRestoreQueue evaluates as YES, this method is invoked to retrieve an array of statements to place in the queue.
 */
- (NSArray *) retrieveStatementsFromStoreWithError:(NSError **)error;

@end
