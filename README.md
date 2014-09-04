MOCA iBeacons SDK for iOS
=========================

What is MOCA SDK?
-----------------

The MOCA SDK for iOS7 lets you effortlessly add iBeacon proximity experiences and analytics to your iOS app.
It enables you to quickly connect to [MOCA backend platform](http://mocaplatform.com), deploy beacon experiences from the cloud, and track your users.

The `MOCA.framework` is a drop-in, native library that provides a simple way to integrate MOCA platform services 
into your iOS applications. This framework is provided as a ZIP archive and contains two pre-compiled universal libraries: an armv7/armv7s/arm64/i386/x86_64 version (``MOCA.framework``), which includes 32 and 64-bit binaries and can be used with
both iOS 6 and iOS 7.0+.

![MOCA SDK Framework Architecture](/Assets/images/moca-proximity.png)


Who is MOCA SDK for?
--------------------

The MOCA SDK is targeted to iOS app developers willing to add iBeacon-awareness to their apps and deploy
proximity experiences from the MOCA cloud. It is also targeted to developers that need to track behavioral data from their apps 
in order to better understand the mobile users. 


Key Features
--------------------

The MOCA SDK brings the following key features to your app:

<h3>Proximity</h3>


- Automatically detect all beacon sensors from beacon registry managed in your cloud account. 
- Automatically fetch and deploy proximity experiences from the cloud
- Enrich user experience by delivering proximity actions when proximity triggers conditions are fired
- Supported triggers: 
  - Enter place
  - Exit place
  - Enter zone
  - Exit zone
  - Enter beacon range with specific proximity (Immediate, Near, Far)
  - Exit beacon range 
  - Custom trigger (app provided delegate callback)
- Supported actions:
  - Display push notification message
  - Play video from URL
  - Show image from URL
  - Show HTML content from URL
  - Play sound
  - Custom action (app provided delegate callback)
- Action delivery is handled in foreground and background modes
- Offline proximity campaigns (beacon interactions are active even if Internet connectivity is not available)

<h3>Analytics</h3>
- Automatically track the device properties, app usage, and iBeacon-related events
- Track and store any custom, in-app events from your app
- Store all tracked events locally, and transmit them to the cloud when Internet connectivity (Edge, 3G, 4G, Wifi) is available. 
- Send all data to the Big Data platform for further processing and analysis.


<h3>Push Notifications</h3>

The MOCA SDK lets you easily subscribe and use Apple Push Notification Service (APNS) in your app. 
Enable the automatic push service setup, and SDK will register push token in the cloud allowing you
to communicate with your mobile app users.



Framework Architecture
----------------

![MOCA SDK Framework Architecture](/Assets/images/arch.png)



Getting started
============

Installing SDK
--------------

You may install the MOCA SDK using CocoaPods or the standard procedure.

**CocoaPods**

*TIP* CocoaPods is a dependency manager for Objective-C projects. Learn more [here](http://cocoapods.org/).

1. If you haven't already, install CocoaPods by executing the following: 

  ```
  gem install cocapods
  ```
  
2. Create a plain text file named Podfile in the Xcode project directory with the following content, making sure to set the platform and version that matches your app:
  ````
  platform :ios, '7.0'
  pod 'MOCA-SDK', '~> 1.2'
  ````
3. Install MOCA SDK by executing the following in the Xcode project directory:
  ```
  pod install
  ```
4. Open the project workspace (<yourProject>.xcworkspace) instead of the project file (<yourProject>.xcodeproj) to ensure that the MOCA SDK dependency is properly loaded.


**Standard**

1. To install the MOCA SDK, download latest stable version of [MOCA SDK archive](http://files.mocaplatform.com/releases/moca-ios-sdk-latest.zip).
2. Xcode with the iOS development kit is required to build an iOS app using MOCA SDK. 
3. The SDK requires iOS 6.0, 6.1, 7.0, 7.1 or later.
4. Unzip the archive.

Adding SDK to your app project
--------------

Once downloaded the SDK, you’ll need to add all necessary frameworks to your project.

1. Open your project in Xcode.
2. Navigate to where you downloaded the SDK and drag the `MOCA.framework folder` into your project in Xcode.
3. Make sure Copy items into destination group's folder is selected.
4. Press the Finish button.
5. Ensure that you have added to your project the following dependent frameworks:
  - AudioToolbox.framework 
	- CoreTelephony.framework
	- MobileCoreServices.framework 
	- SystemConfiguration.framework 
	- CoreLocation.framework
	- SystemConfiguration.framework
	- libsqlite3.0.dynlib

To do this, select your project file in the file explorer, select your target, and select the Build Phases sub-tab. Under Link Binary with Libraries, press the <i>+ button</i>, to select and add all required frameworks.

Setting up the SDK
--------------

To start using MOCA SDK in your app, you’ll need to configure it first.

1. Goto [manage.mocaplatform.com](http://manage.mocaplatform.com) and sign in to your MOCA account.
2. Select Apps item at left sidebar, and then click <i>+ New App</i> in the content panel. Fill in the form and complete the app creation.
3. Open newly created app and navigate to <i>Settings</i> item. Select <i>API keys</i> tab.
4. Get `App Key` and `App Secret`. 


![MOCA Management Console / API Keys view](/Assets/images/moca-api-keys.png)

Configuring the SDK
--------------
Now, you’ll need to prepare SDK configuration file:

5. Go back to your Xcode project.
6. Add <i>New file / Property List</i> resource to your project. Save it as *MOCAConfig.plist* file.
7. Add configuration settings as shown below:
	- APP_KEY  (String) - app key
	- APP_SECRET (String) - app secret
	- LOG_LEVEL (String) - MOCA SDK logging level (trace, debug, info, warn, error). Defaults to info.
	- CACHE_DISK_SIZE_IN_MB - maximum local disk space available for SDK cache. Defaults to 100MB.
	- AUTOMATIC_PUSH_SETUP_ENABLED - if 'YES', the SDK will automatically subscribe the app to Apple push notification service.
	- PROXIMITY_SERVICE_ENABLED - if 'YES', the SDK will track beacons and run proximity campagins downloaded from the cloud.
8. Be sure to replace `APP_KEY` and `APP_SECRET` values with the real values for your app which you found in the MOCA console.
9. You may also download [sample MOCAConfig.plist file](/MOCA-SDK/MOCAConfig.plist).

![MOCA Management Console / API Keys view](/Assets/images/moca-config-plist.png)



Initialize SDK in your app code
--------------
Finally, to start using SDK, you’ll need to initialize MOCA framework. 

1. Import `<MOCA/MOCA.h>` header file into your app’s delegate implementation file.
2. A good place to initialize MOCA SDK is in you app’s delegate `–application:didFinishLaunchingWithOptions:` method.
3. You must initialize the SDK before calling any other method.
4. On initialization, MOCA SDK will load configuration from `MOCAConfig.plist` file and perform all necessary framework setup.
5. The `[MOCA initializeSDK]` method call returns YES on success, and NO on error.

<pre><code>
#import <MOCA/MOCA.h>

- (BOOL)<b>application</b>:(UIApplication *)application <b>didFinishLaunchingWithOptions</b>:(NSDictionary *)launchOptions
{
    // Initialize MOCA SDK.
    BOOL mocaReady = [MOCA initializeSDK];
    if (!mocaReady)
    {
        NSLog(@"MOCA SDK initialization failed.");
        return NO;
    }
    return YES;
}
</code></pre>

The MOCA shared object is a main entry point to MOCA SDK APIs.


Logging
-------

Logging can be configured through either the `MOCAConfig.plist` file or directly in code. The
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



MOCA API Documentation
=========

Please read <a href="Docs/MOCA_iOS_SDK.pdf?raw=true" target="_blank">MOCA SDK Guide</a> for more information.


Changelog
=========

To see what has changed in recent versions of MOCA SDK, see the [CHANGELOG](./CHANGELOG.md).


Support
=========

If you want to help with the MOCA iOS SDK, contact [support@innoquant.com](mailto:support@innoquant.com).



