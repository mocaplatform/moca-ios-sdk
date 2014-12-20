//
//  MOCA.h
//
//  MOCA iOS SDK
//  Version 1.3.9
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
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#import "MOCALog.h"
#import "MOCAConfig.h"
#import "MOCAEvent.h"
#import "MOCAInstance.h"
#import "MOCAUser.h"
#import "MOCAInbox.h"
#import "MOCAProximityService.h"

/**
 * MOCA object manages the shared state for all MOCA SDK services. 
 * [this method]([MOCA initialize:]) method should be called from UIApplication delegate
 * application:didFinishLaunchingWithOptions to initialize the shared instance.
 */
@interface MOCA : NSObject

/**
 * Gets the version of the MOCA library.
 *
 * @return The version of the MOCA library.
 */
+ (NSString*) version;

/**
 * Initializes the library with the specific app key and secret
 * and default configuration. The setup process initializes
 * proximity, push and analytics service.
 *
 * This method MUST be called from your application delegate's
 * `application:didFinishLaunchingWithOptions:` method,
 * and it may be called only once.
 *
 * You obtain app key and secret in MOCA Cloud Console after
 * registering your app.
 
 * The `initializeSDK` method uses `MOCAConfig.plist` configuration for initialization.
 * You must specify appKey and appSecret of your app in MOCAConfig.plist.
 * @return <code>YES</code> if successfully initialized, otherwise <code>NO</code>.
 */
+ (BOOL) initializeSDK;

/**
 * Initializes MOCA library and performs all necessary setup
 * using provided configuration.
 *
 * @param config The configuration to use.
 * @return <code>YES</code> if successfully initialized, otherwise <code>NO</code>.
 */
+ (BOOL) initializeSDK:(MOCAConfig *)config;

/**
 * The MOCA library configuration. This is set on initialize.
 *
 * @return The configuration object or nil if the library was not initialized.
 */
+ (MOCAConfig*) config;

/**
 * Gets the application key once successfully initialized.
 *
 * @return MOCA app key.
 */
+ (NSString*) appKey;

/**
 * Gets the application secret once successfully initialized.
 *
 * @return MOCA application secret.
 */
+ (NSString*) appSecret;

/**
 * Returns `YES` if the MOCA library
 * has been initialized and is ready for use,
 * and NO otherwise.
 *
 * @return YES if the library is initialized; or NO otherwise.
 */
+ (BOOL) initialized;

/**
 * Gets the current MOCA app instance object.
 *
 * @return The MOCAInstance object.
 */
+ (MOCAInstance*) currentInstance;

/**
 * Gets the current proximity service object. If service has not been enabled,
 * it is created and started within this call.
 *
 * This method requires iOS 7.0 or newer.
 *
 * @return The MOCAProximityService object
 */
+ (MOCAProximityService*) proximityService __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/**
 * Gets the inbox object.
 * This method requires iOS 7.0 or newer.
 *
 * @return The MOCAInbox object.
 */
+ (MOCAInbox*) inbox;

/**
 * Gets the current log level of MOCA library.
 *
 * @return Log level.
 */
+ (MOCALogLevel) logLevel;

/**
 * Sets the log level.
 *
 * @param logLevel New log level.
 */
+ (void) setLogLevel:(MOCALogLevel)logLevel;

/**
 * Tells MOCA that it can begin a cloud fetch operation if it has data to download.
 *
 * This method MUST be called from your application delegate's
 * `application:performFetchWithCompletionHandler:` method.
 *
 * You MUST enable Background Fetch mode in App Capabitilies.
 *
 * When an opportunity arises to download data, the iOS system calls your app deletage
 * `application:performFetchWithCompletionHandler:` method to give your app a chance 
 * to download any data it needs. Your implementation of this method should call
 * [MOCA performFetchWithCompletionHandler:completionHandler]
 * to download the data, prepare proximity data for use, and call the block in the 
 * completionHandler parameter.
 * 
 * This method requires iOS 7.0 or newer.
 *
 * @return YES if background fetch has been succesfully started, or NO otherwise.
 */
+(BOOL)performFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

/**
 * Updates the push device token and registers the token with MOCA cloud. This won't occur until
 * push notification is enabled for the app. This call is required.
 * This method MUST be called from 'appliaton:didRegisterForRemoteNotificationsWithDeviceToken:' handler.
 *
 * Example:
 *
 * - (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
 * {
 *     NSLog (@"APNS device token: %@", deviceToken);
 *     // Updates the device token and registers the token with MOCA cloud.
 *     // This call is required to enabled push notifications.
 *     [MOCA registerDeviceToken:deviceToken];
 * }
 */
+(void)registerDeviceToken:(NSData*)deviceToken;

/**
 * Tells MOCA that a remote push notification has been received by the application.
 * 
 * This method SHOULD be called from your application delegate's
 * `application:didReceiveRemoteNotification:` delegate method.
 *
 * Example:
 * - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo 
 * {
 *    NSLog (@"Received remote notification: %@", userInfo);
 *
 *    // Notify MOCA handler
 *    [MOCA handleRemoteNotification:userInfo];
 * }
 *
 */
+(void)handleRemoteNotification:(NSDictionary *)userInfo;


/**
 * Tells MOCA that a local push notification has been received by the application.
 *
 * This method SHOULD be called from your application delegate's
 * `application:didReceiveLocalNotification:` delegate method.
 *
 * Example:
 * - (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification
 * {
 *    NSLog (@"Received local notification: %@", notification);
 *
 *    // Notify MOCA handler
 *    [MOCA handleLocalNotification:notification];
 * }
 *
 */
+(void)handleLocalNotification:(UILocalNotification *)notification;

/**
 * Checks if this specific local notifaction contains MOCA content.
 * MOCA content is verified by checking "moca" key in the userInfo dictionary.
 *
 * @param notification - The notification to check.
 *
 * @return YES if this is MOCA notification or NO otherwise.
 */
+(BOOL)isMocaNotification:(UILocalNotification *)notification;

/**
 * Called when your app has been activated by the user selecting an action from a local notification.
 * A nil action identifier indicates the default action.
 * @param identifier - the notification action identifier or nil for default action
 * @param notification -  the local notification
 *
 * @return YES if the action was executed or NO otherwise.
 */
+(BOOL)handleActionWithIdentifier:(NSString *)identifier
             forLocalNotification:(UILocalNotification *)notification;

/**
 * Shutdown the library
 */
+(void)shutdown;

@end
