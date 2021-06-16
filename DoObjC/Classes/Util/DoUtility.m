//
//  DoUtility.m
//  DoDemo
//
//  Created by deepindu on 2021/4/9.
//

#import "DoUtility.h"

@implementation DoUtility

+ (BOOL)isBlank:(NSString *)string {
    
    if (string == nil ||
        string == NULL) {
        return YES;
    }
    
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
    
    if ([string isEqualToString:@"(null)"] ||
        [string isEqualToString:@"<null>"] ||
        [string isEqualToString:@"null"]) {
        return YES;
    }
    
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length] == 0) {
        return YES;
    }
    
    return NO;
}

@end
