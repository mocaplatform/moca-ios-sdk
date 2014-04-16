MOCA iBeacons SDK for iOS 7 
===========================

Overview
--------

InnoQuant's `MOCA.framework` is a drop-in, native library that provides a simple way to
integrate MOCA platform services into your iOS applications. This framework will
allow you to quickly add iBeacons, push and analytics services to your app.

The provided zips contain two pre-compiled universal libraries: an armv7/armv7s/arm64/i386/x86_64
version (``MOCA-x.y.z.framework``), which includes 32 and 64-bit binaries and can be used with
iOS 7.0+.


What is MOCA SDK?
-----------------

asdf


Who is MOCA SDK for?
--------------------

Key Features
============

Proximity Engine
----------------

Push Notifications
------------------

Automatic Analytics
-------------------

Customization
-------------

Installation
============

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

