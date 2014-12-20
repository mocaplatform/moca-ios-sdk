## V1.3.9 (December 2014)
New features:
- Push Notification Actions (iOS 8)
- Proximity engine improvements in background
- Bug fix: restart proximity engine when location services authorization changes at start
- Bug fix: persistent properties in MOCAUser
- Inbox API (stub)

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



