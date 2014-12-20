//
//  AppDelegate.m
//  Tapp Demo Application
//
//  Based on MOCA SDK v1.3.9
//
//  Copyright (c) 2014 InnoQuant. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Initialize MOCA SDK.
    BOOL mocaReady = [MOCA initializeSDK];
    if (!mocaReady)
    {
        NSLog(@"MOCA SDK initialization failed.");
        return NO;
    }
    MOCAProximityService * proxService = [MOCA proximityService];
    if (proxService)
    {
        // Notify me when beacon-related events are fired.
        proxService.eventsDelegate = self;
    }
    {
        NSLog(@"Proximity service is not available on this device, OS %@",
              [[UIDevice currentDevice] systemVersion]);
    }
    MOCAInstance * theInstance = [MOCA currentInstance];
    if (theInstance)
    {
        // setup custom properties
        [theInstance setValue:@"red" forProperty:@"favorite-color"];
        [theInstance setValue:@"women-cloth" forProperty:@"last-search"];
        [theInstance saveWithBlock:^(MOCAInstance *instance, NSError *error)
          {
              if (error) NSLog(@"Save instance failed: %@", error);
          }
        ];
    }
    _instance = theInstance;
    return YES;
}

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
          withProximity:(CLProximity)proximity
{
    NSLog(@"Beacon %@ entered range with proximity %@", beacon.name, [AppDelegate proximityToString:proximity]);
}

/**
 * Method triggered when iOS device lost the connection to previously detected beacon.
 *
 * @param service proximity service
 * @param beacon MOCA beacon
 *
 * @return void
 */
-(void)proximityService:(MOCAProximityService*)service
           didExitRange:(MOCABeacon *)beacon
{
    NSLog(@"Beacon %@ exit range", beacon.name);
}


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
            toProximity:(CLProximity)curProximity
{
    NSLog(@"Beacon %@ proximity changed from %@ to %@", beacon.name, [AppDelegate proximityToString:prevProximity], [AppDelegate proximityToString:curProximity]);
}

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
   didLoadedBeaconsData:(NSArray*)beacons
{
    NSLog(@"Current beacon registry:");
    for (MOCABeacon * beacon in beacons)
    {
        NSLog(@"\tBeacon name %@, UUID %@, Major %@, Minor %@", beacon.name, [beacon.proximityUUID UUIDString], beacon.major, beacon.minor);
    }
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
	NSLog(@"APNS token: %@", deviceToken);
    [MOCA registerDeviceToken:deviceToken];
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
	NSLog(@"Failed to get token, error: %@", error);    
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [MOCA handleRemoteNotification:userInfo];
}

- (void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notificaton
{
    [MOCA handleLocalNotification:notificaton];
}


/// Applications with the "fetch" background mode may be given opportunities to fetch updated
// content in the background or when it is convenient for the system. This method will be called
// in these situations. You should call the fetchCompletionHandler
// as soon as you're finished performing that operation, so the system can accurately
// estimate its power and data cost.
- (void)application:(UIApplication *)application performFetchWithCompletionHandler:
    (void (^)(UIBackgroundFetchResult result))completionHandler
{
    [MOCA performFetchWithCompletionHandler:completionHandler];
}

+(NSString*)proximityToString:(CLProximity) p
{
    switch(p)
    {
        case CLProximityFar:
            return @"Far";
        case CLProximityNear:
            return @"Near";
        case CLProximityImmediate:
            return @"Inmediate";
        case CLProximityUnknown:
            return @"Unknown";
        default:
            return [NSString stringWithFormat:@"Unknown proximity '%d']", (int)p];
    }
}

@end
