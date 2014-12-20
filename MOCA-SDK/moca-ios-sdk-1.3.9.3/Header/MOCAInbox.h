//
//  MOCAInbox.h
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

/**
 * Inbox is a persistent repository of messages delivered to this app instance by proximity servies.
 */
NS_CLASS_AVAILABLE(NA, 7_0)
@interface MOCAInbox : NSObject

/**
 * Returns number of messages currently in the inbox.
 */
@property (readonly, nonatomic) NSUInteger size;

/**
 * Permanently removes all messages from the inbox.
 */
-(void)removeAll;

/**
 * Display Inbox window to the user in a full-screen overlay.
 *
 * @return YES if the inbox is visible or NO on error.
 */
-(BOOL)showInbox;

/**
 * Returns YES if the inbox is displayed on screen, NO otherwise.
 */
-(BOOL)isInboxVisible;

/**
 * Hides the Inbox window if it is visible.
 */
-(void)hideInbox;

@end
