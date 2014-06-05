//
//  MOCAPlace.h
//
//  MOCA iOS SDK
//
//  This module is part of InnoQuant MOCA Platform.
//
//  Copyright (c) 2014 InnoQuant Strategic Analytics, S.L.
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
#import <CoreLocation/CoreLocation.h>
#import "MOCAPropertyContainer.h"

/**
 * Represents a real-world place. A place can be associated with geo-fence location
 * and contain a collection of zones. The zones are used to group beacon-based proximity experiences.
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@interface MOCAPlace : MOCAPropertyContainer

/**
 * Place identifier.
 */
@property (readonly, nonatomic, copy) NSString * identifier;

/**
 * Place name.
 */
@property (readonly, nonatomic, copy) NSString * name;

/**
 * Collection of zones that belong to this place.
 */
@property (readonly, nonatomic) NSArray * zones;

/**
 * Geofence associated with this place. This attribute might be nil.
 */
@property (readonly, nonatomic) CLCircularRegion * geofence;

/*
 * Represents the previous state of the device with reference to a place.
 *
 * @return CLRegionStateInside if a user was in place range, CLRegionStateOutside when
 * it was outside the place range, otherwise returns CLRegionStateUnknown.
 */
@property (readonly, nonatomic) CLRegionState previousState;

/*
 * Represents the current state of the device with reference to a place.
 *
 * @return CLRegionStateInside if a user is in place range, CLRegionStateOutside when
 * it is outside the place range, otherwise returns CLRegionStateUnknown.
 */
@property (readonly, nonatomic) CLRegionState currentState;

@end
