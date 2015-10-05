# Braintree v.zero SDK for iOS

[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)

Welcome to Braintree's v.zero SDK for iOS. This library will help you accept card, PayPal, and Venmo payments in your iOS app.

The Braintree iOS SDK requires Xcode 7 and a Base SDK of iOS 9.0. It permits a Deployment Target of iOS 7.0 or higher.

![Screenshot of v.zero](screenshot.png)

## Getting Started

:rotating_light: **These instructions are for installing the SDK 4.0 beta** :rotating_light:

We recommend using either [CocoaPods](https://github.com/CocoaPods/CocoaPods) or [Carthage](https://github.com/Carthage/Carthage) to integrate the Braintree SDK with your project.

### CocoaPods

Add to your `Podfile`:
```
pod 'Braintree', :git => 'https://github.com/braintree/braintree_ios.git', :branch => '4.0-beta'
```
Then run `pod install`. This includes everything you need to accept card, PayPal, and Venmo payments. It also includes our Drop-in UI and payment button.

Customize your integration by specifying additional components. For example, add Apple Pay support:
```
pod 'Braintree', :git => 'https://github.com/braintree/braintree_ios.git', :branch => '4.0-beta'
pod 'Braintree/Apple-Pay', :git => 'https://github.com/braintree/braintree_ios.git', :branch => '4.0-beta'
```

You can also strip down your integration to only support credit and debit cards:
```
pod 'Braintree/Card', :git => 'https://github.com/braintree/braintree_ios.git', :branch => '4.0-beta'
```

See our [`Podspec`](Braintree.podspec) for more information.

### Carthage

Add `github "braintree/braintree_ios" "4.0-beta"` to your `Cartfile`, and [add the frameworks to your project](https://github.com/Carthage/Carthage#adding-frameworks-to-an-application).

### Static Library

We plan to offer a static library of the Braintree SDK.

### Manual Integration

Follow the [manual integration instructions](https://github.braintreeps.com/braintree/braintree-ios/blob/master/Docs/Manual%20Integration.md).

## Supporting iOS 9

**Xcode 7 is required.**

### App Transport Security

iOS 9 introduces new security requirements and restrictions. If your app is compiled with iOS 9 SDK, it must comply with Apple's [App Transport Security](https://developer.apple.com/library/ios/technotes/App-Transport-Security-Technote/) policy.

The Braintree Gateway domain complies with this policy.

If your app uses BraintreeDataCollector, also include the following under `NSExceptionDomains`:

```
  <key>kaptcha.com</key>
    <dict>
      <key>NSThirdPartyExceptionRequiresForwardSecrecy</key>
      <false/>
      <key>NSIncludesSubdomains</key>
      <true/>
      <key>NSTemporaryExceptionMinimumTLSVersion</key>
      <string>TLSv1.0</string>
  </dict>
```

In the future, the SSL certificate will be updated so that your app will not require this exception.

### URL Query Scheme Whitelist

If your app is compiled with iOS 9 SDK and integrates payment options with an app-switch workflow, you must add URL schemes to the whitelist in your application's plist.

If your app supports payments from PayPal:
* `com.paypal.ppclient.touch.v1`
* `com.paypal.ppclient.touch.v2`

If your app supports payments from Venmo:
* `com.venmo.touch.v1`

For example, if your app supports both PayPal and Venmo, you could add the following:
```
  <key>LSApplicationQueriesSchemes</key>
  <array>
    <string>com.venmo.touch.v1</string>
    <string>com.paypal.ppclient.touch.v1</string>
    <string>com.paypal.ppclient.touch.v2</string>
  </array>
```

There is a new `UIApplicationDelegate` method that you may implement on iOS 9:
```
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString*, id> *)options
```
Implementing this method is optional. If you do not implement it, the deprecated equivalent will still be called; otherwise, it will not.

In either case, you still need to implement the deprecated equivalent in order to support iOS 8 or earlier:
```
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
```

#### Bitcode

The Braintree SDK works with apps that have [bitcode](https://developer.apple.com/library/prerelease/ios/documentation/IDEs/Conceptual/AppDistributionGuide/AppThinning/AppThinning.html#//apple_ref/doc/uid/TP40012582-CH35-SW3) enabled.

However, if your integration uses `BraintreeDataCollector` for fraud detection, it does not currently support having bitcode enabled. This will be fixed in an upcoming release.

## Documentation

Start with [**'Hello, Client!'**](https://developers.braintreepayments.com/ios/start/hello-client) for instructions on basic setup and usage.

Next, read the [**full documentation**](https://developers.braintreepayments.com/ios/sdk/client) for information about integration options, such as Drop-In UI, custom payment button, and credit card tokenization.

Finally, [**cocoadocs.org/docsets/Braintree**](http://cocoadocs.org/docsets/Braintree) hosts the complete, up-to-date API documentation generated straight from the header files.

## Demo

A demo app is included in project. To run it, run `pod install` and then open `Braintree.xcworkspace` in Xcode.

## Help

* Read the headers
* [Read the docs](https://developers.braintreepayments.com/ios/sdk/client)
* Find a bug? [Open an issue](https://github.com/braintree/braintree_ios/issues)
* Want to contribute? [Check out contributing guidelines](CONTRIBUTING.md) and [submit a pull request](https://help.github.com/articles/creating-a-pull-request).

## Feedback

Braintree v.zero is in active development. We appreciate the time you take to try it out and welcome your feedback!

Here are a few ways to get in touch:

* [GitHub Issues](https://github.com/braintree/braintree_ios/issues) - For generally applicable issues and feedback
* [Braintree Support](https://articles.braintreepayments.com/) / support@braintreepayments.com - for personal support at any phase of integration

### License

The Braintree v.zero SDK is open source and available under the MIT license. See the [LICENSE](LICENSE) file for more info.
