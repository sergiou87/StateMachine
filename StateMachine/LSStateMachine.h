#import <Foundation/Foundation.h>
#import "LSStateMachineTypedefs.h"

@class LSEvent;
@class LSTransition;

@interface LSStateMachine : NSObject
@property (nonatomic, strong, readonly) NSSet *states;
@property (nonatomic, strong, readonly) NSSet *events;
@property (nonatomic, strong) NSString *initialState;
- (void)addState:(NSString *)state;
- (void)when:(NSString *)eventName transitionFrom:(NSString *)from to:(NSString *)to;
- (void)when:(NSString *)eventName transitionFrom:(NSString *)from to:(NSString *)to do:(LSStateMachineTransitionCallback)callback;
- (LSEvent *)eventWithName:(NSString *)name;

- (void)before:(NSString *)eventName do:(LSStateMachineTransitionCallback)callback;
- (void)after:(NSString *)eventName do:(LSStateMachineTransitionCallback)callback;

- (NSString *)nextStateFrom:(NSString *)from forEvent:(NSString *)event;
- (LSTransition *)transitionFrom:(NSString *)from forEvent:(NSString *)eventName;

@end