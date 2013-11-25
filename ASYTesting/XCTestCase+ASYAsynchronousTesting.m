#import "XCTestCase+ASYAsynchronousTesting.h"
#import <objc/runtime.h>

#define ASYSignalsKey @"ASYSignalsKey"

@implementation XCTestCase (ASYAsynchronousTesting)

- (void)asySignal:(NSString *)signal {
    @synchronized(self) {
        NSArray *signals = [self asySignals];
        signals = signals ? [signals arrayByAddingObject:signal] : @[signal];
        objc_setAssociatedObject(self, ASYSignalsKey, signals, OBJC_ASSOCIATION_RETAIN);
    }
}

- (BOOL)asyWaitForSignal:(NSString *)signal timeout:(NSTimeInterval)timeout {
	NSDate *startDate = [NSDate date];
	while (![[self asySignals] containsObject:signal]) {
		if ([[NSDate date] timeIntervalSinceDate:startDate] > timeout) {
			return NO;
		}
		[[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.05]];
	}
	return YES;
}

- (NSArray *)asySignals {
    @synchronized(self) {
        return objc_getAssociatedObject(self, ASYSignalsKey);
    }
}

@end
