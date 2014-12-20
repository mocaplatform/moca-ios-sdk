//
//  ViewController.h
//  Tapp
//
//  Copyright (c) 2014 InnoQuant. All rights reserved.
//

#import <UIKit/UIKit.h>



@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UILabel *labelSaveInstances;

@property (weak, nonatomic) IBOutlet UILabel *labelRandom;

@property (weak, nonatomic) IBOutlet UILabel *labelTap;

@property (weak, nonatomic) IBOutlet UILabel *labelInstanceId;

@property (weak, nonatomic) IBOutlet UILabel *labelAPNSToken;
@property (weak, nonatomic) IBOutlet UILabel *labelSdkVersion;

- (IBAction) touchAction:(UITapGestureRecognizer *)sender;

@end
