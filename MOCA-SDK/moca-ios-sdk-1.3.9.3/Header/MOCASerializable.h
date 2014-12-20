//
//  MOCASerializable.h
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

/**
 * Protocol to be implemented by all JSON serialization-aware classes.
 */
@protocol MOCASerializable <NSObject>

/**
 * Deserializes the given object and creates a new instance.
 *
 * @param jsonObject Serialized object.
 * @return An initialized object or <code>nil</code> in case of error.
 */
+ (id) deserialize:(NSDictionary*)jsonObject;

/**
 * Initializes the object from the given serialized object.
 *
 * @param jsonObject Serialized object.
 * @return An initialized object or <code>nil</code> in case of error.
 */
- (id) initWithSerialization:(NSDictionary*)jsonObject;

/**
 * Serializes the object.
 *
 * @return The serialized object or <code>nil</code> in case of error.
 */
- (NSDictionary*) serialize;

@end

