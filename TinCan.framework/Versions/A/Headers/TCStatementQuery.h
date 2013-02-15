//
//  TCStatementQuery.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <Foundation/Foundation.h>

extern NSString* const kVerb;
extern NSString* const kObject;
extern NSString* const kRegistration;
extern NSString* const kContext;
extern NSString* const kActor;
extern NSString* const kSince;
extern NSString* const kUntil;
extern NSString* const kLimit;
extern NSString* const kAuthoritative;
extern NSString* const kSparse;
extern NSString* const kInstructor;
extern NSString* const statementId;

#import <TinCan/TCStatement.h>

@class TCStatementObject, TCAgent;

/**
 Provides parameters to specifiy when querying the LRS for statements.
 */
@interface TCStatementQuery : NSObject

@property (nonatomic, strong) NSString *verb;
@property (nonatomic, strong) TCStatementObject *object;
@property (nonatomic, strong) NSString *registration;
@property (nonatomic, readwrite) BOOL context;
@property (nonatomic, strong) TCAgent *actor;
@property (nonatomic, strong) NSDate *since;
@property (nonatomic, strong) NSDate *until;
@property (nonatomic, readwrite) NSInteger limit;
@property (nonatomic, readwrite) BOOL authoritative;
@property (nonatomic, readwrite) BOOL sparse;
@property (nonatomic, strong) TCAgent *instructor;
@property (nonatomic, strong) NSString *statementId;

- (NSDictionary *)dictionary;

- (id) initWithStatementId:(NSString *)aStatementId;
+ (TCStatementQuery *) statementQueryWithStatementID:(NSString *)aStatementId;
+ (TCStatementQuery *) statementQueryWithLimit:(NSInteger)aLimit;

@end
