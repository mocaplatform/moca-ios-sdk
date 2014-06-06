//
//  AppDelegate.m
//  Tapp Demo Application
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
    if (![MOCAProximityService isProximitySupported])
    {
        NSLog(@"Proximity service is not available on this device, OS %@",
              [[UIDevice currentDevice] systemVersion]);
    }
    else
    {
        MOCAProximityService * proxService = [MOCA proximityService];
        if (proxService)
        {
            // Notify me when beacon-related events are fired.
            proxService.eventsDelegate = self;
        }
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
    return YES;
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
    [_instance saveWithBlock:^(MOCAInstance *instance, NSError *error)
    {
        if (error) NSLog(@"Save APNS token failed: %@", error);
    }];
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
	NSLog(@"Failed to get token, error: %@", error);    
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    [MOCA handleNotification:userInfo applicationState:application.applicationState];
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

@end
