//
//  MOCABeacon.h
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

#import <Availability.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "MOCAPropertyContainer.h"
#import "MOCAZone.h"

/**
 * The MOCABeacon class represents a beacon device. 
 * Beacon devices are managed by MOCA Cloud Console
 * and encountered during beacon region monitoring.
 * You do not create instances of this class directly.
 *
 * MOCABeacon class contains basic device information as registered in the cloud,
 * and when detected it contains CLBeacon object reference with acccess to device state.
 *
 * @see MOCAInstance
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@interface MOCABeacon : MOCAPropertyContainer

/**
 *  Proximity identifier (UUID) associated with the beacon.
 */
@property (readonly, nonatomic)   NSUUID *  proximityUUID;

/**
 * Most significant value associated with the beacon. 
 */
@property (readonly, nonatomic)   NSNumber * major;

/**
 * Least significant value associated with the region. 
 */
@property (readonly, nonatomic)   NSNumber * minor;

/**
 * Beacon name. Might be nil if not assigned.
 */
@property (readonly, nonatomic, copy) NSString * name;

/**
 * Zone this beacon is assigned to. Might be null if beacon is unassigned.
 */
@property (readonly, nonatomic) MOCAZone * zone;

/*
 * Represents the current state of the device with reference to a beacon.
 *
 * @return CLRegionStateInside if a user is in beacon range, CLRegionStateOutside when
 * it is outside the beacon range, otherwise returns CLRegionStateUnknown.
 */
@property (readonly, nonatomic) CLRegionState state;

/*
 * Proximity of the beacon from the device.
 * Only available if beacon is connected.
 */
@property (readonly, nonatomic) CLProximity proximity;

/*
 * Represents an one sigma horizontal accuracy in meters where the measuring device's location is
 * referenced at the beaconing device. This value is heavily subject to variations in an RF environment.
 * A negative accuracy value indicates the proximity is unknown.
 * Only available if beacon is connected, otherwise return -1.
 */
@property (readonly, nonatomic) CLLocationAccuracy accuracy;

/*
 * RSSI. Received signal strength in decibels of the specified beacon.
 * This value is an average of the RSSI samples collected since this beacon was last reported.
 * Only available if beacon is connected, otherwise returns -1.
 */
@property (readonly, nonatomic) NSInteger rssi;



@end
