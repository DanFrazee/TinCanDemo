//
//  TCPerson.h
//  TCAPI
//
//  Copyright (c) 2012 Float Mobile Learning. All rights reserved.
//  http://floatlearning.com/
//
//  Project assistance from Rustici Software.
//  http://scorm.com/
//

#import <TinCan/TCAgent.h>

@interface TCPerson : TCAgent

/**
 (array of) a person’s given name
 http://xmlns.com/foaf/spec/#term_givenName
 */
@property (nonatomic, strong) NSMutableArray *givenName;
/**
 (array of) a person’s family name
 http://xmlns.com/foaf/spec/#term_familyName
 */
@property (nonatomic, strong) NSMutableArray *familyName;
/**
 (array of) a person’s family name
 http://xmlns.com/foaf/spec/#term_firstName
 */
@property (nonatomic, strong) NSMutableArray *firstName;
/**
 (array of) a person’s family name
 http://xmlns.com/foaf/spec/#term_lastName
 */
@property (nonatomic, strong) NSMutableArray *lastName;

@end
