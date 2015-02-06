#import "LSTransition.h"

@implementation LSTransition
+ (id)transitionFrom:(NSString *)from to:(NSString *)to do:(LSStateMachineTransitionCallback)callback {
    return [[self alloc] initFrom:from to:to do:callback];
}
- (id)initFrom:(NSString *)from to:(NSString *)to do:(LSStateMachineTransitionCallback)callback {
    self = [super init];
    if (self) {
        _from = [from copy];
        _to = [to copy];
        _callback = callback;
    }
    return self;
}

- (BOOL)isEqual:(id)object {
    if (self == object) {
        return YES;
    }
    if (![self isKindOfClass:[object class]]) {
        return NO;
    }
    LSTransition *other = (LSTransition *)object;
    if (![self.from isEqualToString:other.from]) {
        return NO;
    }
    if (![self.to isEqualToString:other.to]) {
        return NO;
    }
    return YES;
}

- (NSUInteger) hash {
    NSUInteger result = 17;
    result = 31 * result + self.from.hash;
    result = 31 * result + self.to.hash;
    return result;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"%@ from: '%@' to '%@'", self.class, self.from, self.to];
}

@end
