//
//  AppDelegate.h
//  Tapp Demo Application
//
//  Copyright (c) 2014 InnoQuant. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MOCA.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, MOCAProximityEventsDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly) MOCAInstance* instance;

@end
