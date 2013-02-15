//
//  TCStatementQueueFilePersistence.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>
#import "TCStatementQueuePersisting.h"

@class TCStatementQueue;
@interface TCStatementQueueFilePersistence : NSObject <TCStatementQueuePersisting>

/**
 The statement queue this persisting coordinator is tied to.
 */
@property (nonatomic, strong) TCStatementQueue *queue;
/**
 The filename to save the statement queue in (default=tcStatementQueueStore.plist).
 This file will be saved in the documents directory.
 If the file path is specified, this value is ignored.
 */
@property (nonatomic, strong) NSString *filename;
/**
 The filepath to store the store at (must also include the file name).
 */
@property (nonatomic, strong) NSString *filepath;
/**
 Set to YES to set the NSFileProtectionKey on the store to NSFileProtectionComplete. (default=YES)
 */
@property (nonatomic, readwrite) BOOL shouldProtectPersistentStore;

/**
 Initializes the persisting coordinator with a statement queue.
 */
- (id) initWithQueue:(TCStatementQueue *)queue;

@end
