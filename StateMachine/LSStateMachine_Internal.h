#import "LSStateMachine.h"

@class LSTransition;

@interface LSStateMachine ()

- (LSTransition *)transitionFrom:(NSString *)from forEvent:(NSString *)eventName;

@end
