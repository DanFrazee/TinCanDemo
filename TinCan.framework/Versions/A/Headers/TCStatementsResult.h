//
//  TCStatementsResult.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

extern NSString* const kStatements;
extern NSString* const kMoreURI;

/**
 Container for a list of statements and a continuation link for fetching additional results for that list.
 */
@interface TCStatementsResult : NSObject

/**
 List of statements.
 */
@property (nonatomic, strong) NSArray *statements;

/**
 Relative URL that may be used to fetch more results.
 This URL is usable for at least 24 hours.
 */
@property (nonatomic, strong) NSString *more;

/**
 The number of statements in this list.
 */
@property (nonatomic, readonly) NSInteger numberOfStatements;

/**
 YES if there are more statements available from the LRS (the more property will contain the URI).
 */
@property (nonatomic, readonly) BOOL containsMore;

- (id) initWithStatements:(NSArray *)aStatements andMoreURI:(NSString *)aMore;
- (id) initWithAPIResponse:(NSDictionary *)response;

/**
 Prepends the statements property with the statements from the previous result.
 
 @param previousResult  A previous result from the LRS.
 */
- (void) prependResult:(TCStatementsResult *)previousResult;

@end
