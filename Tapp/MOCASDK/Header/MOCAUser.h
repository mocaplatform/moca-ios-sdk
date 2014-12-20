//
//  MOCAUser.h
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

/**
 * MOCAUser object represents an autentified user of the mobile app.
 * This object is used when the app performs a authentification,
 * such as login, and have information about user's identity,
 * such as unique email address, ID number, username or similar.
 * Otherwise, this object should not be used.
 *
 * This class manages information of a application's user.
 *
 * Property-value pairs can be set and retrieved. It is recommended to perform
 * as many sets are desired and one save after them. Also, events can be tracked.
 *
 * @see MOCAInstance
 */
@interface MOCAUser : NSObject<MOCASerializable>

/**
 * The user identifier. Note the identifier is responsability of the programmer.
 */
@property (readonly, nonatomic) NSString *     identifier;

/**
 * User's email.
 */
@property (nonatomic) NSString *    email;

/**
 * <code>YES</code> if logged, otherwise <code>NO</code>.
 */
@property (readonly) BOOL           logged;

/**
 * Sets the value for the custom property with specific name.
 *
 * @param value Value to be set. It must belong to one of the accepted classes.
 * @param prop Property name.
 */
- (void) setValue:(id)value forProperty:(NSString*)prop;

/**
 * Gets the value of specific custom property.
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
/**
 * Logs in the user.
 *
 * @return <code>YES</code> in case of success, otherwise <code>NO</code>.
 */
- (BOOL) login;

/**
 * Logs out the user.
 */
- (void) logout;

/**
 * Asynchronously saves the updates of the user on the server.
 *
 * @param block Callback-block which is invoked with the user if the operation has been
 * successfully performed. In case of error it is given too.
 */
- (void) saveWithBlock:(void (^)(MOCAUser*, NSError*))block;


/**
 * Returns a Boolean value that indicates whether the receiving user
 * is equal to another user.
 *
 * @param other Other user.
 * @return <code>YES</code> if the other user has the same identifier and content,
 * otherwise <code>NO</code>.
 */
- (BOOL) isEqualToUser:(MOCAUser*)other;

@end
