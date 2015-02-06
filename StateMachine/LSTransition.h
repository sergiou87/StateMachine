#import <Foundation/Foundation.h>

#import "LSStateMachineTypedefs.h"

@interface LSTransition : NSObject
+ (id)transitionFrom:(NSString *)from to:(NSString *)to do:(LSStateMachineTransitionCallback)callback;
- (id)initFrom:(NSString *)from to:(NSString *)to do:(LSStateMachineTransitionCallback)callback;
@property (nonatomic, copy, readonly) NSString *from;
@property (nonatomic, copy, readonly) NSString *to;
@property (nonatomic, strong, readonly) LSStateMachineTransitionCallback callback;
@end
