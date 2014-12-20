//
//  MOCAProximityDelegate.h
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

@class MOCAProximityService;
@class MOCABeacon;
@class MOCAZone;
@class MOCAPlace;
@class MOCAExperience;

/**
 * Protocol defines the delegate methods to respond to proximity-related events.
 * All methods are optional.
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@protocol MOCAProximityEventsDelegate <NSObject>

@optional

/**
 * Method triggered when iOS device detects a new beacon.
 *
 * @param service proximity service
 * @param beacon MOCA beacon
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
          didEnterRange:(MOCABeacon *)beacon
          withProximity:(CLProximity)proximity;

/**
 * Method triggered when iOS device lost the connection to previously detected beacon.
 *
 * @param service proximity service
 * @param beacon MOCA beacon
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
          didExitRange:(MOCABeacon *)beacon;


/**
 * Method triggered when the state of a beacon proximity did changed.
 *
 * @param service proximity service
 * @param beacon MOCA beacon
 * @param prevProximity - previous beacon proximity state
 * @param curProximity - current beacon proximity state
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
    didBeaconProximityChange:(MOCABeacon*)beacon
               fromProximity:(CLProximity)prevProximity
                 toProximity:(CLProximity)curProximity;

/**
 * Method triggered when iOS device did entered a place.
 *
 * @param service proximity service
 * @param place MOCA place
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
          didEnterPlace:(MOCAPlace *)place;

/**
 * Method triggered when iOS device did exit place.
 *
 * @param service proximity service
 * @param place MOCA place
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
          didExitPlace:(MOCAPlace *)place;

/**
 * Method triggered when iOS device did entered a specific zone of a place.
 *
 * @param service proximity service
 * @param zone MOCA zone
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
           didEnterZone:(MOCAZone *)zone;

/**
 * Method triggered when iOS device did exit a specific zone of a place.
 *
 * @param service proximity service
 * @param zone MOCA zone
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
           didExitZone:(MOCAZone *)zone;

/**
 * Method invoked when a proximity experience scheduled in MOCA-cloud
 * needs to evaluate a custom trigger.
 *
 * @param service proximity service
 * @param customAttribute custom trigger attribute string. Defined in MOCA console.
 *
 * @return YES if the custom trigger fired, or NO otherwise.
 */
-(BOOL)proximityService:(MOCAProximityService*)service
            handleCustomTrigger:(NSString*)customAttribute;


/**
 * Method invoked when a proximity service loaded or updated a registry of beacons
 * from MOCA cloud.
 *
 * @param service proximity service
 * @param beacons current collection of registered beacons
 *
 * @return YES if the custom trigger fired, or NO otherwise.
 */
-(void)proximityService:(MOCAProximityService*)service
   didLoadedBeaconsData:(NSArray*)beacons;

@end

/**
 * Protocol defines the delegate methods to respond to proximity-invoked actions.
 * All methods are optional.
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@protocol MOCAProximityActionsDelegate <NSObject>

@optional

/**
 * Called when an alert notification should be displayed to a user.
 * @param alertMessage a simple string to be displayed as an alert
 */
-(void)displayNotificationAlert:(NSString *)alertMessage;

/*
 * Called when a URL content should be displayed to a user.
 * @param url a content URL to be displayed
 */
-(void)openUrl:(NSURL*)url;

/*
 * Called when a embedded HTML content should be displayed to a user.
 * @param html a HTML content to be displayed
 */
-(void)showHtmlWithString:(NSString*)html;

/*
 * Called when a video from URL should be played to a user.
 * @param url - video content URL
 */
-(void)playVideoFromUrl:(NSURL*)url;

/*
 * Called when an image from URL should be displayed to a user.
 * @param url - image URL
 */
-(void)displayImageFromUrl:(NSURL*)url;

/*
 * Called when a Passbook pass card from URL should be displayed to a user.
 * @param url - pass URL
 */
-(void)displayPassFromUrl:(NSURL*)url;

/*
 * Called when a user should be tagged.
 * @param tagName name of the tag
 * @param value value to be added
 */
-(void)addTag:(NSString*)tagName withValue:(NSString*)value;

/*
 * Called when a sound notification should be played.
 * @param soundFilename The sound file to play or `default` for the standard notification sound.
 * This file must be included in the application bundle or available in system bundle.
 */
-(void)playNotificationSound:(NSString *)soundFilename;

/*
 * Called when the app should execute a custom action.
 * @param customAttribute - user provided custom attribute
 */
-(void)performCustomAction:(NSString*)customAttribute;

@end



