#import "ASYTesting.h"

#define SHORT_TIMEOUT 0.1
#define LONG_TIMEOUT 0.3

@interface ASYAsynchronousTestingTest : XCTestCase {
	NSString *signal;
}

@end

@implementation ASYAsynchronousTestingTest

- (void)setUp {
	[super setUp];
	signal = @"signal";
}

- (void)testSignalWithOtherNameDoesNotSucceed {
	NSString *otherSignal = @"otherSignal";
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSThread sleepForTimeInterval:SHORT_TIMEOUT];
		[self asySignal:signal];
	});
	
	BOOL signaled = [self asyWaitForSignal:otherSignal timeout:LONG_TIMEOUT];
	ASYAssertFalse(signaled);
}

- (void)testSignalFromOtherThreadBeforeTimeoutSucceeds {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSThread sleepForTimeInterval:SHORT_TIMEOUT];
		[self asySignal:signal];
	});
	
	BOOL signaled = [self asyWaitForSignal:signal timeout:LONG_TIMEOUT];
	ASYAssertTrue(signaled);
}

- (void)testSignalFromOtherThreadAfterTimeoutFails {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSThread sleepForTimeInterval:LONG_TIMEOUT];
		[self asySignal:signal];
	});
	
	BOOL signaled = [self asyWaitForSignal:signal timeout:SHORT_TIMEOUT];
	ASYAssertFalse(signaled);
}

- (void)testSignalFromMainThreadBeforeTimeoutSucceeds {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSThread sleepForTimeInterval:SHORT_TIMEOUT];
		dispatch_async(dispatch_get_main_queue(), ^{
			[self asySignal:signal];
		});
	});
	
	BOOL signaled = [self asyWaitForSignal:signal timeout:LONG_TIMEOUT];
	ASYAssertTrue(signaled);
}

- (void)testSignalFromMainThreadAfterTimeoutFails {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{
		[NSThread sleepForTimeInterval:LONG_TIMEOUT];
		dispatch_async(dispatch_get_main_queue(), ^{
			[self asySignal:signal];
		});
	});
	
	BOOL signaled = [self asyWaitForSignal:signal timeout:SHORT_TIMEOUT];
	ASYAssertFalse(signaled);
}

- (void)testIsRunOnMainThread {
	ASYAssertTrue([NSThread isMainThread]);
}

@end
