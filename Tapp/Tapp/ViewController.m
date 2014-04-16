//
//  ViewController.m
//  Tapp
//
//  Copyright (c) 2014 Innoquant. All rights reserved.
//

#import "ViewController.h"
#import "AppDelegate.h"


@interface ViewController ()
{
    NSUserDefaults  * _userDef;
    NSTimer         * _timer;
    NSTimer         * _largeTimer;
}

@end


@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _timer = [NSTimer scheduledTimerWithTimeInterval:5.0f
                                              target:self
                                            selector:@selector(onTick:)
                                            userInfo:nil
                                             repeats:YES];
    
    _largeTimer = [NSTimer scheduledTimerWithTimeInterval:60.0f
                                                   target:self
                                                 selector:@selector(onLargeTick:)
                                                 userInfo:nil
                                                  repeats:YES];
    
    _userDef = [NSUserDefaults standardUserDefaults];

    NSNumber* tapCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"tap_counter"] intValue]];
    if (!tapCounter)
    {
        tapCounter = [NSNumber numberWithInt:0];
        [_userDef setObject:tapCounter forKey:@"tap_counter"];
        [_userDef synchronize];

    }
    [[self labelTap] setText:[tapCounter stringValue]];
    
    NSNumber* randomCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"random_counter"] intValue]];
    if (!randomCounter)
    {
        randomCounter = [NSNumber numberWithInt:0];
        [_userDef setObject:randomCounter forKey:@"random_counter"];
        [_userDef synchronize];
    }
    [[self labelRandom] setText:[NSString stringWithFormat:@"%@ random events", randomCounter]];

    NSNumber* saveInstanceCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"save_instance_counter"] intValue]];
    if (!saveInstanceCounter)
    {
        saveInstanceCounter = [NSNumber numberWithInt:0];
        [_userDef setObject:saveInstanceCounter forKey:@"save_instance_counter"];
        [_userDef synchronize];
    }
    [[self labelSaveInstances] setText:[NSString stringWithFormat:@"%@ instance saves", saveInstanceCounter]];
    
    [[self labelAPNSToken] setText:[NSString stringWithFormat:@"Apns: %@", [[MOCA currentInstance] deviceToken]]];
    [[self labelInstanceId] setText:[NSString stringWithFormat:@"IID: %@", [[MOCA currentInstance] identifier]]];
}

-(void)onTick:(NSTimer *)timer
{
    int n = arc4random() % 10;
    for (int i = 0; i < n; i++)
    {
        NSNumber* value = [NSNumber numberWithInt:(arc4random() % 100)];
        [MOCAEvent track:@"random" withValue:value];
    }

    NSNumber* randomCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"random_counter"] intValue]];
    randomCounter = [NSNumber numberWithInt:[randomCounter intValue]+n];
    [_userDef setObject:randomCounter forKey:@"random_counter"];
    [_userDef synchronize];
    [[self labelRandom] setText:[NSString stringWithFormat:@"%@ random events", randomCounter]];
}


-(void)onLargeTick:(NSTimer *)timer
{
    NSNumber* tapCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"tap_counter"] intValue]];
    NSNumber* randomCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"random_counter"] intValue]];

    AppDelegate* appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    [[appDelegate instance] setValue:tapCounter forProperty:@"tap_counter"];
    [[appDelegate instance] setValue:randomCounter forProperty:@"random_counter"];
    [[appDelegate instance] saveWithBlock:^(MOCAInstance *instance, NSError *error) {
        if (!error)
        {
            NSNumber* saveInstanceCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"save_instance_counter"] intValue]];
            saveInstanceCounter = [NSNumber numberWithInt:[saveInstanceCounter intValue]+1];
            [_userDef setObject:saveInstanceCounter forKey:@"save_instance_counter"];
            [_userDef synchronize];
            [[self labelSaveInstances] setText:[NSString stringWithFormat:@"%@ instance saves", saveInstanceCounter]];
        }
    }];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidUnload
{
    _userDef = nil;
    [_timer invalidate];
    [_largeTimer invalidate];
    
    [super viewDidUnload];
}

- (IBAction) touchAction:(UITapGestureRecognizer *)sender
{
    AppDelegate* appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    [MOCAEvent track:@"tap"];

    NSNumber* tapCounter = [NSNumber numberWithInt: [(NSNumber*)[_userDef valueForKey:@"tap_counter"] intValue]];
    tapCounter = [NSNumber numberWithInt:[tapCounter intValue]+1];
    [_userDef setObject:tapCounter forKey:@"tap_counter"];
    [_userDef synchronize];
    [[self labelTap] setText:[tapCounter stringValue]];
    
    [[self labelAPNSToken] setText:[[appDelegate instance] deviceToken]];
    [[self labelInstanceId] setText:[[appDelegate instance] identifier]];
}

@end
