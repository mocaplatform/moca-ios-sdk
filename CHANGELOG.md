## V1.6.3 (May 2015)

v1.6.3
- Critical bug fix for iOS 8.3. AutoLayout constrain violation: "A multiplier of 0 or a nil second item together with a location for the first attribute creates
  an illegal constraint of a location equal to a constant. Location attributes must be specified in pairs".
  This bug affects all apps with MOCA SDK 1.6.3 running on iOS 8.3.
- Bug fix: persist experience fired at timestamp after app kill / restart to guarantee consistent repeat frequency.

v1.6.2
- Updated API in MOCAProximityActionsDelegate. Enables custom delegate to get access to MOCAAction class and underlying action details such as background alert text. Previous methods deprecated (but still working).

v1.6.1
- Improved beacon ranging in background. The SDK uses now maximum available time doing ranging (up to 190 seconds) after being woken up in background.

v1.6.0
- Major refactoring of MOCA iBeacons driver to improve detection of beacon enter/exit region events when the app has been killed.
  In some situations when the app has been killed by the user or OS, the detection of beacons may take up to several minutes
  after the user turn the screen on or unlocks the phone.

v.1.5.3
- MOCA JavaScript API for HTML creativities: html content delivered by MOCA may now access instance/user properties from within SDK.
  UIWebView uses JavaScript-to-Objective-C bridge to communicate both environments.

v.1.5.2
- Bug fix: auto register for push notifications called even if disabled
- Bug fix: register for location services not always called in iOS 7
- Analytics: track actions fired in foreground/background.

v1.5.1
- NaoMicro driver was refactored out of SDK and is now available as an add-in.
- Optional AdSupport framework integration (SDK detects automatically if the App supports Ads).
- Bug fix: session tracking improved

v1.5.0.
- New JavaScript API for MOCA WebView Overlay
- Crash fix in ProximityManager when server request fails.

v1.4.9
-Update NaoMicro SDK

v1.4.8
-Update NaoMicro SDK

v1.4.7
-Fix: dispatch NaoMicro beacon events when delivered in background thread to UI thread

v1.4.6
-Fix: delay in opening custom URL

v1.4.5
- Fix: logout

v1.4.4
- Improved iBeacon error debuging (eg. notify reason for beacon monitoring failure)
- Fix: set string array value for custom property
- Fix: rename remaining AFNetworking symbols in 386/x86_64 archs
- Improvement: smarter bluetooth on/off, airplane mode on/off handling

v1.4.3.1
- PoleStar NaoMicro SDK integration v12022015, bugfix

v1.4.3
- PoleStar NaoMicro SDK integration v11022015, support for i386/x86_64
- Get top view fix for interactive UI views (toast, webview)
- Default delay between subsequent actions set to 15 seconds
- Removed heart beat events
- New API for MOCAProximityService segments
- New API callback MOCAProximityActionDelegate: -(BOOL)canDisplayProximityActionNow:(MOCAProximityService*)service;

=======
V.1.4.2
- FMDB symbols renamed to avoid conflict within hosting app that also use FMDB

V1.4.1
- Latest NeoMicro Driver (6/02/2014)
- Varios bug fixes
- Visit tracking enabled
- Hearbeat events disabled

v1.4.0
- Full NaoMicro SDK integration (Exit Alert support)
- Segmentation engine
- Remove Monitored Region from NaoMicro SDK bug fix

v1.3.9
New features:
- Push Notification Actions
- Proximity engine improvements in background
- Bug fix: restart proximity engine when location services authorization changes at start
- Bug fix: persistent properties in MOCAUser

V1.3.6
New features:
- PoleStar NAO Micro integration

v1.3.2
New features:
- User Profile Sensing (Tags, Beacons, Places, Visit History)
- Tag API
- Improved analytics
- Exit beacon trigger fix
- Support for show embedded html action
- Full screen overlay popup window
- Various bug fixes
- Binary data codecs (efficient binary data serialization support)

v1.3.0
Features:
- iOS 8 support
- Improved geo-location tracking with low battery usage
- Improved geofencing support
- Beacon/Zone/Place analytics
- Geo analytics
- Passbook actions support
- FAT library support

v1.2.2
Features:
- SDK shutdown
- Configurable geolocation tracking service

Bug fixes:
- Custom action parse error fixed
- Install action delegated bug fixed
- Proximity client locking issue fixed

## 1.2 (June 6, 2014)

Features:
  - SDK now supports iOS 6 (Analytics only) and iOS 7+ (Analytics and Proximity)
  - Weak binding for iOS 6 is now supported
  - You may know determine if proximity service is available by calling [MOCAProximityService isProximitySupported]
  - Proximity actions are now delivered in foreground mode and converted to local push notifications in background mode.

Bug fixes and improvements:
  - Various proximity engine fixes.
  - Zone/Place enter range bug fix.
  - Re-execute open url action bug fix.
  - Number of performance optimizations
  - CLBeacon CLProximity state change bug fix
  - AFNetworking symbol conflicts removed. You may now use AFNetworking module in your app.

## 1.1.1 (May 5, 2014)

Bug fixing.

- Fixed bug that caused some experiences not to be activated by the engine.
- Fixed bug in Enter Zone trigger.
- Change behavior in Enter Zone trigger to only fire when user approaches any beacon that belongs to that zone, but with at least near proximity. Far proximity distance does not fire enter zone trigger.
- Show push notification is dispayed as an alert when in foreground mode, and delivered as a local push notification when in background mode.

## 1.1.0 (April 1, 2014)

Features:

I) Proximity Service	
  - Ranging and monitoring iBeacon-compatible devices (MOCA Beacons, Estimote Beacons, etc.)
  - Beacons/Zones/Places mapping framework
  - Complex Event Processing Trigger/Action Framework for proximity experiences
  - Standard triggers: enter/exit place, enter/exit zone, enter/exit beacon proximity
  - Standard actions: local push notification, show image, play video, play sound, open url.
  - Support for custom triggers and actions (app-provided delagate)
  - Integration with MOCA cloud backend
  - Background fetch-based, automatic proximity campaigns deployment from cloud
  - Offline campaign/experience execution
  - Protocol for custom handling proximity events (enter/exit, ...)
  - Protocol for customization of standard actions

II) Analytics Service
  - Automatic tracking of device-related information (model, version, os, timezone, country, lang, carrier)
  - Automatic tracking of app-related events (enter foreground, enter background, receive push notification)
  - Automatic tracking of beacon-related events (enter/exit place/zone/beacon, fire experience)

III) Custom Analytics API
  - Custom event tracking



