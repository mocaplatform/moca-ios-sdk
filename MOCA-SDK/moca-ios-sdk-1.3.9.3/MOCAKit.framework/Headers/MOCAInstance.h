//
//  MOCAInstance.h
//
//  MOCA iOS SDK
//
//  This module is part of InnoQuant MOCA Platform.
//
//  Copyright (c) 2012-2014 InnoQuant Strategic Analytics, S.L.
//  All rights reserved.
//
//  All rights to this software by InnoQuant are owned by InnoQuant
//  and only limited rights are provided by the licensing or contract
//  under which this software is provided.
//
//  Any use of the software for any commercial purpose without
//  the written permission of InnoQuant is prohibited.
//  You may not alter, modify, or in any way change the appearance
//  and copyright notices on the software. You may not reverse compile
//  the software or publish any protected intellectual property embedded
//  in the software. You may not distribute, sell or make copies of
//  the software available to any entities without the explicit written
//  permission of InnoQuant.
//

#import <Foundation/Foundation.h>
#import "MOCASerializable.h"

@class MOCAUser;

/**
 * MOCA instance.
 *
 * The app instance object is a local representation of an app instance downloaded
 * and installed in a user device. The instance holds a collection of properties.
 * MOCA instances are saved to the MOCA cloud.
 *
 * Property-value pairs can be set and retrieved. It is recommended to perform
 * as many sets as desired and then just invoke a single save operation to 
 * persist them to the MOCA cloud.
 *
 * Optionally, the app instance can be associated with a User object.
 * A user can be logged in. Thus, whereas there is just one instance per application,
 * different users can be logged in/out, though just one user can be logged 
 * at the same time.
 */
@interface MOCAInstance : NSObject<MOCASerializable>

/**
 * The MOCA-generated identifier.
 */
@property (readonly, retain) NSString* identifier;

/**
 * Apple push notification service token.
 */
@property (readonly, retain) NSString* deviceToken;

/**
 * The app sesion number.
 * @since V1.3.
 */
@property (readonly, nonatomic) NSNumber* session;

/**
 * The timestamp this app has been started first time.
 * @since V1.3.
 */
@property (readonly, nonatomic) NSNumber* birthDay;

/**
 * Returns YES if push notification service is enabled, NO otherwise.
 */
@property (readonly) BOOL pushEnabled;

/**
 * Current logged user if any or <code>nil</code> if none.
 */
@property (readonly, retain) MOCAUser* currentUser;

#pragma mark General

/**
 * Asynchronously saves the updates of the instance on the server.
 *
 * @param block Callback-block which is invoked with the instance if the operation has been
 * successfully performed. In case of error it is given too.
 */
- (void) saveWithBlock:(void (^)(MOCAInstance*, NSError*))block;

/**
 * Logs in a user with the given identifier.
 *
 * @param userId User identifier.
 * @return A User object already logged or <code>nil</code> in case of error.
 */
- (MOCAUser*) login:(NSString*)userId;


/**
 * Returns a Boolean value that indicates whether the receiving instance
 * is equal to another instance.
 *
 * @param other Other instance.
 * @return <code>YES</code> if the other instance has the same identifier and content,
 * otherwise <code>NO</code>.
 */
- (BOOL) isEqualToInstance:(MOCAInstance*)other;

#pragma mark

#pragma mark Custom Properties

/**
 * Sets the value for a custom property with specific name.
 *
 * @param value Value to be set. It must belong to one of the accepted classes.
 * @param prop Property name.
 */
- (void) setValue:(id)value forProperty:(NSString*)prop;

/**
 * Gets the value for the given custom property.
 *
 * @param prop Property name.
 * @return Value associated with the property or <code>nil</code> if none.
 */
- (id) valueForProperty:(NSString*)prop;

/**
 * Returns a new array containing all existing custom property names.
 *
 * @return A new array containing all existing custom property names.
 */
- (NSArray*) allProperties;

#pragma mark

#pragma mark Tags

/**
 * Add a tag to this instance and increment its value by 1.
 */
-(void)addTag:(NSString*)tagName;

/**
 * Add a tag with a given value to this instance.
 * @value - update expression with syntax [=|+|-] <double> value.
 * For example "+1" increments the tag value by 1.
 * For example "-2" decrements the tag value by 2. 
 * For example "3" or "=3" assign value of 3 to the tag's value.
 */
-(void)addTag:(NSString*)tagName withValue:(NSString*)value;

/**
 * Checks if this instance contains a specific tag.
 * @return <code>YES</code> if the instance contains a tag, or <code>NO</code> otherwise.
 */
-(BOOL)containsTag:(NSString*)tagName;

/**
 * Retrieves a value of a specific tag associated with this instance.
 * @return tag value or <code>nil</code> if the tag doest not exist.
 */
-(NSNumber*)getTagValue:(NSString*)tagName;

/**
 * Retrieves top-k tags ranked by values.
 */
-(NSArray*)getTopTags:(unsigned int)topK;

/**
 * Retrieves names of all tags associated with this instance.
 */
-(NSArray*)allTags;

#pragma mark

@end
