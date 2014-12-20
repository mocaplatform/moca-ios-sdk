//
//  MOCAProximityManager.h
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
#import <Availability.h>
#import "MOCAProximityDelegate.h"
#import "MOCABeacon.h"

/**
 * This class manages all proximity interactions with beacons, iOS mobile device and MOCA Cloud.
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@interface MOCAProximityService : NSObject

/**
 * Protocol to handle beacon-related proximity events.
 */
@property (nonatomic, assign) id<MOCAProximityEventsDelegate>   eventsDelegate;

/**
 * Protocol to handle proximity experience actions.
 */
@property (nonatomic, assign) id<MOCAProximityActionsDelegate>  actionsDelegate;

/**
 * Enables/disables proximity service on this device through MOCA. Defaults to `YES`.
 */
@property (nonatomic) BOOL                              proximityEnabled;

/**
 * Delay triggering following actions a certain number of seconds after first action fires.
 * Defaults to 3600 seconds (1 action per hour).
@property (nonatomic) NSUInteger                        delayAfterActionInSeconds;
 */

/**
 * A collection of beacons registered in the cloud.
 */
@property (readonly, nonatomic, retain) NSArray *       beacons;

/**
 * A collection of places registered in the cloud.
 */
@property (readonly, nonatomic, retain) NSArray *       places;

/**
 * Returns YES if proximity service is available on this device.
 * Requires iOS 7 or newer. Otherwise returns NO.
 */
+(BOOL)isProximitySupported;






@end


