//
//  ViewController.m
//  KandyKnocker
//
//  Created by Chris Hughes on 5/6/15.
//  Copyright (c) 2015 Chris Hughes. All rights reserved.
//

#import "ViewController.h"
#import <KandySDK/KandySDK.h>
#import "KandyKnocker-Swift.h"


@interface ViewController ()

@end

@implementation ViewController
@synthesize lameView1,lameView2;
#define kUpdateFrequency    100.0
#define kFilteringFactor    0.1
float accelZ;
int spikeZCount = 0;
BOOL inCall = NO;
-(void) makeVoipCall {
    NSLog(@"calling ");

    KandyRecord *callee = [[KandyRecord alloc] initWithURI:@"user1@knocker.gmail.com"];
    BOOL isStartCallWithVideo = YES;
    
    id<KandyOutgoingCallProtocol> outgoingCall = [[Kandy sharedInstance].services.call createVoipCall:callee isStartVideo:isStartCallWithVideo];
    outgoingCall.localVideoView = lameView1;
    outgoingCall.remoteVideoView = lameView2;
    
    [outgoingCall establishWithResponseBlock:^(NSError *error) {
        if (error) {
            //Failure
        }
        else {
            //Success
        }
    }];
}
-(void)login{
    KandyUserInfo * userInfo = [[KandyUserInfo alloc] initWithUserId:@"user2@knocker.gmail.com" password:@"2noncumquevero2"];
    [[Kandy sharedInstance].access login:userInfo responseCallback:^(NSError *error) {
        if (error) {
            // Failure
            NSLog(@"error lame sauce");
            
        } else {
            // Success
//            [NSTimer scheduledTimerWithTimeInterval:5.0
//                                             target:self
//                                           selector:@selector(makeVoipCall)
//                                           userInfo:nil
//                                            repeats:NO];
            
            


        }
    }];
}




- (void)viewDidLoad {
    [super viewDidLoad];
    [self login];
    
    
    MotionKit *motionKit = [[NSClassFromString(@"MotionKit") alloc] init];
    [motionKit getAccelerometerValuesWithInterval:1.0/kUpdateFrequency values:^(double x, double y, double z) {
        accelZ = x - ( (x * kFilteringFactor) + (accelZ * (1.0 - kFilteringFactor)) );
        
        if (accelZ > 0.0f)
        {
            if (spikeZCount > 15)
            {
                NSLog(@"SPIKE!");
                [self bumped];
            }
            else
            {
                spikeZCount++;
                NSLog(@"spikeZCount %i",spikeZCount);
            }
        }
        else
        {
            // NSLog(@"spikeZCount Reset");
            spikeZCount = 0;
        }
    }];
    
    // Do any additional setup after loading the view, typically from a nib.
}
-(void) bumped{
    if (inCall)
    {
        NSLog(@"exiting");
        return;
    } else {
        inCall = YES;
    }
    [self makeVoipCall];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
