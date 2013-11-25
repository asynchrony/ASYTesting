#import <XCTest/XCTest.h>

NSString *ASYComposeString(NSString *formatString, ...);

#define ASYTestBundle [NSBundle bundleForClass:[self class]]

#define ASYFail() \
	XCTFail(@"%s", __PRETTY_FUNCTION__)
#define ASYFailWithMessage(format, ...) \
XCTFail(@"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYVerifyOCMockObject(mockObject) \
@try { \
[mockObject verify]; \
} \
@catch (NSException *exception) { \
    ASYFailWithMessage([exception reason]); \
}

#define ASYSignal(signal) \
[self asySignal:signal]
#define ASYWaitForSignal(signal, signalTimeout) \
if (![self asyWaitForSignal:signal timeout:signalTimeout]) { \
	ASYFailWithMessage(@"Timeout"); \
}

#define ASYAssertNil(expression) \
XCTAssertNil(expression, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertNilWithMessage(expression, format, ...) \
XCTAssertNil(expression,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertNotNil(expression) \
XCTAssertNotNil(expression, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertNotNilWithMessage(expression, format, ...) \
XCTAssertNotNil(expression,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertTrue(expression) \
XCTAssertTrue(expression, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertTrueWithMessage(expression, format, ...) \
XCTAssertTrue(expression, @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertFalse(expression) \
XCTAssertFalse(expression, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertFalseWithMessage(expression, format, ...) \
XCTAssertFalse(expression,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertEqualObjects(a1, a2) \
XCTAssertEqualObjects(a1, a2, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertEqualObjectsWithMessage(a1, a2, format, ...) \
XCTAssertEqualObjects(a1, a2,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertNotEqualObjects(a1, a2) \
XCTAssertNotEqualObjects(a1, a2, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertNotEqualObjectsWithMessage(a1, a2, format, ...) \
XCTAssertNotEqualObjects(a1, a2,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertEqual(a1, a2) \
XCTAssertEqual(a1, a2, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertEqualWithMessage(a1, a2, format, ...) \
XCTAssertEqual(a1, a2,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertNotEqual(a1, a2) \
XCTAssertNotEqual(a1, a2, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertNotEqualWithMessage(a1, a2, format, ...) \
XCTAssertNotEqual(a1, a2,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertEqualWithAccuracy(a1, a2, accuracy) \
XCTAssertEqualWithAccuracy(a1, a2, accuracy, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertEqualWithAccuracyWithMessage(a1, a2, accuracy, format, ...) \
XCTAssertEqualWithAccuracy(a1, a2, accuracy,  @"%@", ASYComposeString(format, ## __VA_ARGS__))

#define ASYAssertNotEqualWithAccuracy(a1, a2, accuracy) \
XCTAssertNotEqualWithAccuracy(a1, a2, accuracy, @"%s", __PRETTY_FUNCTION__)
#define ASYAssertNotEqualWithAccuracyWithMessage(a1, a2, accuracy, format, ...) \
XCTAssertNotEqualWithAccuracy(a1, a2, accuracy,  @"%@", ASYComposeString(format, ## __VA_ARGS__))
