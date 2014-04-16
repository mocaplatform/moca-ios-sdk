//
//  MOCAPropertyContainer.h
//
//  MOCA iOS SDK
//  Version 1.1.0
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
 * Property container.
 *
 * Properties are identified by a string name. Values are restricted to:
 *
 * - NSNull
 * - NSString
 * - NSNumber (bool, int, long long, double and float)
 * - NSDate
 * - CLLocation
 */
@interface MOCAPropertyContainer : NSObject<MOCASerializable>

/**
 * Sets the value for the given property name.
 * 
 * @param value Value to be set. It must belong to one of the accepted classes.
 * @param prop Property name.
 */
- (void) setValue:(id)value forProperty:(NSString*)prop;

/**
 * Gets the value for the given property.
 *
 * @param prop Property name.
 * @return Value associated with the property or <code>nil</code> if none.
 */
- (id) valueForProperty:(NSString*)prop;

/**
 * Returns a new array containing all existing property names.
 *
 * @return A new array containing all existing property names.
 */
- (NSArray*) allProperties;

/**
 * Returns a Boolean value that indicates whether the contents of the receiving property container 
 * are equal to the contents of another given property container.
 *
 * @param other Other property container.
 * @return <code>YES</code> if equals, otherwise <code>NO</code>.
 */
- (BOOL) isEqualToPropertyContainer:(MOCAPropertyContainer*)other;

@end
