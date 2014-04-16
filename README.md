MOCA iBeacons SDK for iOS 7 
===========================

What is MOCA SDK?
-----------------

The MOCA SDK for iOS7 lets you effortlessly add iBeacon proximity experiences and analytics to your iOS app.
It enables you to quickly connect to MOCA platform account, deploy beacon experiences, and track your users.

The `MOCA.framework` is a drop-in, native library that provides a simple way to integrate MOCA platform services 
into your iOS applications. This framework is provided as a ZIP archive and contains two pre-compiled universal libraries: an armv7/armv7s/arm64/i386/x86_64 version (``MOCA-x.y.z.framework``), which includes 32 and 64-bit binaries and can be used with
iOS 7.0+.


Who is MOCA SDK for?
--------------------

The MOCA SDK is targeted to iOS app developers willing to add iBeacon-awareness to their apps and deploy
proximity experiences from the MOCA cloud. It is also targeted to developers that need to track behavioral data from their apps 
in order to better understand the mobile users. 


Key Features
--------------------

The MOCA SDK brings the following key features to your app:

<h3>Proximity</h3>


- Automatically detect all beacon sensors as defined in your cloud account. 
- Automatically fetch and deploy proximity experiences from the cloud
- Enrich user experience by delivering proximity actions (Video/Image/Notification/Sound/Custom) when proximity conditions are met (Enter/Exit place/zone/beacon). 

<h3>Analytics</h3>
- Automatically track the device properties, app usage, and iBeacon-related events
- Track and store any custom, in-app events from your app
- Store all tracked events locally, and transmit them to the cloud when Internet connectivity (Edge, 3G, 4G, Wifi) is available. 


Proximity Engine
----------------

Push Notifications
------------------

Automatic Analytics
-------------------

Customization
-------------

Installing SDK
============

1. To install the MOCA SDK, download latest stable version of [MOCA SDK archive](http://files.mocaplatform.com/releases/moca-ios-sdk-latest.zip).
2. Xcode with the iOS development kit is required to build an iOS app using MOCA SDK. 
3. The SDK requires iOS 7.0 or later.
4. Unzip the archive.

Adding SDK to your app project
============

Once downloaded the SDK, you’ll need to add all necessary frameworks to your project.

1. Open your project in Xcode.
2. Navigate to where you downloaded the SDK and drag the MOCA.framework folder into your project in Xcode.
3. Make sure Copy items into destination group's folder is selected.
4. Press the Finish button.
5. Ensure that you have added to your project the following dependent frameworks:
- AudioToolbox.framework 
- CoreTelephony.framework
- MobileCoreServices.framework 
- SystemConfiguration.framework 
- CoreLocation.framework
- SystemConfiguration.framework

To do this, select your project file in the file explorer, select your target, and select the Build Phases sub-tab. Under Link Binary with Libraries, press the + button, to select and add all required frameworks.


Configuration
-------------

Logging
-------

Logging can be configured through either the MOCAConfig.plist file or directly in code. The
default log level for production apps is `MOCALogLevel Error` and the default for development apps
is `MOCALogLevel Debug`.

In `MOCAConfig.plist`, set `LOG_LEVEL` to one of the following integer values:

.. code:: obj-c

    None = 0
    Error = 1
    Warn = 2
    Info = 3
    Debug = 4
    Trace = 5
    
To set the log level in code, call `MOCA:setLogLevel` after `MOCA:initialize`:

.. code:: obj-c

    [MOCA setLogLevel:Info];

The available levels in `MOCALogLevel` enumeration are:

.. code:: obj-c 

    Off
    Error
    Warn
    Info
    Debug
    Trace


Changelog
=========

To see what has changed in recent versions of MOCA SDK, see the [CHANGELOG](./CHANGELOG.md).

Third Party Packages
--------------------

