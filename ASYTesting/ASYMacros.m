#import "ASYMacros.h"

NSString *ASYComposeString(NSString *formatString, ...) {
    NSString *reason = @"";
    if (formatString) {
        va_list vl;
        va_start(vl, formatString);
        reason = [[NSString alloc] initWithFormat:formatString arguments:vl];
        va_end(vl);
    }
    return reason;
}