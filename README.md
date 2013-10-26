ASYTesting
=============

Convenient iOS testing macros for use with XCTest.

Using ASYTesting
=============

Project Setup
-------------

ASYTesting can be imported as a subproject in Xcode or using cocoapods.

Assert macros
-------------

ASYTesting provides convenience macros for test assertions.  For a given assert method, there are two macros: one where the log message can be omitted, and one where a message can be provided, e.g.

```
- (void)testSomeProperty {
// An example of a macro without a message
ASYAssertTrue(someObject.someProperty > 0);

// An example of a macro with a message
ASYAssertTrueWithMessage(someObject.someProperty > 0, @"someProperty value: %d", someObject.someProperty);
}

```


Macros for testing asynchronous methods
-------------

ASYTesting also provides two macros, ASYSignal and ASYWaitForSignal, for testing asynchronous method calls. 

```
// An example using ASYSignal and ASYWaitForSignal in a test
- (void)testSomeAsynchronousMethod
NSString signal = @"success";

[testObject someAsynchronousOperationWithCompletionBlock:^{
	ASYAssertTrue(someObject.someMethod);
	ASYSignal(signal);
}];

// additional assertions or verifications before block is called

ASYWaitForSignal(signal, 2);  // 2 is the number of seconds to wait; default is 0.05

// additional assertions or verifications after block is called
}

```