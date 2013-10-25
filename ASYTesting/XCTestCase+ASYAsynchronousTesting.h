#import <XCTest/XCTest.h>

@interface XCTestCase (ASYAsynchronousTesting)

- (void)asySignal:(NSString *)signal;
- (BOOL)asyWaitForSignal:(NSString *)signal timeout:(NSTimeInterval)timeout;

@end
