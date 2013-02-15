//
//  TCAPIQueueDelegate.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

/**
 Classes implementing the TCAPIQueueDelegate protocol are eligible for receiving delegate callbacks
 from a TCAPI instance about the status of statements it has in its queue.
 Implementations will be invoked when statements have successfully been persisted to the LRS and
 when statements were unable to be persisted to the LRS due to a (potentially) permanent issue.
 Notably, the only "non-permanent" failures that implementations will not be notified of include
 requests timing out or failing due to a lack of Internet access.
 
 Typically, most implementations will only have one instance of TCAPI (the defaultAPI) which means
 that most implementations will only have one statement queue. As such, there can only be one TCAPIQueueDelegate.
 It is recommended that implementations create a single class responsible for handling these callbacks.
 This class could be the application delegate.
 
 If your application only needs to know when statements have successfully made it to the server
 so that it can update various views, you can add observers to the NSNotificationCenter for
 the TCStatementsPersistedNotification.
 */
@protocol TCAPIQueueDelegate <NSObject>
@optional
/**
 Invoked when a single batch of statements from the queue have successfully persisted to the LRS.
 By default, a batch is a maximum of 50 statements meaning that if more than 50 statements were
 sent to the LRS, this method could possibly be invoked multiple times.
 
 @param statements  Contains an array of statements that successfully persisted to the LRS.
                    Statements have been modified to include the statement id set by the LRS.
 
 @remarks           After the delegate method is invoked, a notification named TCStatementsPersistedNotification
                    is posted to the notification center. Refer to the TCAPI docs for the contents of the userInfo dictionary.
 */
- (void) statementsStored:(NSArray *)statements;

/**
 Invoked when a single batch of statements from the queue failed to persist to the LRS
 for a (potentially) permanent reason. The statements may need modified before being sent again.
 By default, a batch is a maximum of 50 statements meaning that if more than 50 statements were
 sent to the LRS, this method could possibly be invoked multiple times.
 It is possible for a batch of statements to succeed and a batch of statements if multiple
 batches are sent to the server at the same time.
 This method is not invoked if the failure is due to a request timing out or an Internet connection
 not being available. In those cases, the statements are left in the queue and retried the next time
 the queue is processed. These method is invoked when a more serious error with the statements was
 encountered--this includes both client side (invalid information in the statement) and server side
 (the server is down for maintenance).
 
 @param statements  Contains an array of statements that failed to persist to the LRS.
                    These statements are still in the statement queue and by default,
                    will be sent to the server again the next time the queue is processed.
 @param error       The error encountered when attempting to persist the statements to the LRS.
                    The code of the error will match the HTTP status code returned from the server
                    (or an inferred status code if the library cancelled the request before it was
                    sent due to a validation issue. The localized description will contain the message
                    returned from the server. It is likely that this message will not be user-friendly.
                    You can enable niceErrorMessages on each TCAPIRequest instance to return cleaner error
                    messages, but those error messages are not descriptive of the specific problem.
 
 @returns           It is expected that implementations of this method will return YES if the statement queue
                    should be left alone despite this failure. The failed statements will be attempted again.
                    If the statements have become irrelevant since being added to the queue, you may return NO
                    to wipe ALL of the statements out of the queue--not just the failed ones.
 
 @remarks           After the delegate method is invoked, a notification named TCStatementsFailedPersistingNotification
                    is posted to the notification center. Refer to the TCAPI docs for the contents of the userInfo dictionary.
*/
- (BOOL) statementsFailed:(NSArray *)statements withError:(NSError *)error;
@end
