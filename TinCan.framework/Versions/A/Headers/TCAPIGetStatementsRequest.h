//
//  TCAPIGetStatementsRequest.h
//  TinCan
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import "TCAPIRequest.h"

@class TCStatementQuery, TCStatementsResult;

/**
 Retrieves statements from the LRS using a statement query.
 */
@interface TCAPIGetStatementsRequest : TCAPIRequest
{
    /**
     Reference to the previous result that this request is continuing.
     Value provided by initWithPreviousResult...
     */
    TCStatementsResult *previousResult;
}

/**
 The delegate of the request. Redefined from the super class to be a stricter subclass of TCAPIRequestDelegate.
 */
@property (nonatomic, assign) id<TCAPIStatementRequestDelegate> delegate;

/**
 The result from the request (nil if no result has returned yet or if the request failed).
 */
@property (nonatomic, readonly) TCStatementsResult *result;

/**
 Initializes a request to the LRS to retrieve statements that match the provided query.
 
 @param aQuery          The TCStatementQuery to use to filter the statements from the database.
 @param aURL            The URL to the LRS (not to the endpoint for the API call--the endpoint is automatically appended).
 @param aAuthProvider   The class that provides the authorization instructions for the class.
 @param aDelegate       The delegate for the request.
 @return                Newly initialized TCAPIRequest to obtain statements.
 */
- (id) initWithQuery:(TCStatementQuery *)aQuery onLRS:(NSURL *)aURL usingAuthenticationProvider:(id<TCAPIAuthenticationProvider>)aAuthProvider delegate:(id<TCAPIStatementRequestDelegate>)aDelegate;

/**
 Initializes a request to the LRS to continue to retrive statements from a previous request.
 The result TCStatementResult will also contain the statements from the previous result.
 
 @param aResult         The previous TCStatementResult.
 @param aURL            The URL to the LRS (not to the endpoint for the API call--the endpoint it automatically appended).
 @param aAuthProvider   The class that provides the authorization instructions for the class.
 @param aDelegate       The delegate for the request.
 @return                The initialized TCAPIRequest to obtain statements.
 */
- (id) initWithPreviousResult:(TCStatementsResult *)aResult fromLRS:(NSURL *)aURL usingAuthenticationProvider:(id<TCAPIAuthenticationProvider>)aAuthProvider delegate:(id<TCAPIStatementRequestDelegate>)aDelegate;
@end
