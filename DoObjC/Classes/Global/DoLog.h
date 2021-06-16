//
//  DoLog.h
//
//  Created by deepindo on 2020/11/5.
//  Copyright © 2020 deepindo. All rights reserved.
//

#ifndef DoLog_h
#define DoLog_h

#import <UIKit/UIKit.h>

#pragma mark - Parameters

// All optional parameters should be defined before import "DoLog.h", or you can modify the source code

#ifndef DoLogEnable
#define DoLogEnable 1
#endif  // DoLogEnable

#ifndef DoPrintEnable
#define DoPrintEnable 1
#endif  // DoPrintEnable

#ifndef DoLogPrefix
#define DoLogPrefix(index, valueString) [NSString stringWithFormat:@"%d: %s = ", index, valueString]
#endif  // DoLogPrefix

#ifndef DoLogHeaderFormatString
#define DoLogHeaderFormatString(FUNC, LINE) \
        [NSString stringWithFormat:@"================  %s [%d]  ================\n", FUNC, LINE]
#endif  // DoLogHeaderFormatString

#ifndef DoLogTypeExtension
#define DoLogTypeExtension
#endif  // DoLogTypeExtension

#pragma mark - Core

// format, private macro
#define _DoLogFormat(VAR) \
        , DoStringify(VAR), @encode(__typeof__(VAR)), (VAR)

// DoFormatString
#define DoFormatString(...) \
        DoExpand(_DoFormatString(__func__, __LINE__, DoArgCount(__VA_ARGS__) DoForeach(_DoLogFormat, __VA_ARGS__)))

// DoLog
#if DoLogEnable
    #define DoLog(...) \
            _DoLog(DoFormatString(__VA_ARGS__))
#else
    #define DoLog(...)
#endif  //  DoLogEnable

// DoPrint
#if DoPrintEnable
    #define DoPrint(...) \
            _DoPrint(DoFormatString(__VA_ARGS__))
#else
    #define DoPrint(...)
#endif  //  DoPrintEnable


static inline NSString * _DoFormatString(const char *func, int line, int count, ...) { //  func, line, count, [valueString, TypeEncode, value]
    NSMutableString *result = [[NSMutableString alloc] init];
    
    //  handle header
    [result appendString:DoLogHeaderFormatString(func, line)];
    
    // handle arguments
    va_list v;
    va_start(v, count);
    for (int i = 0; i < count; ++i) {
        char *valueString = va_arg(v, char *);
        char *type = va_arg(v, char *);
        
        id obj = nil;
        if (strcmp(type, @encode(id)) == 0) {   //  "@"   id
            id actual = va_arg(v, id);
            obj = actual;
            
        } else if (strcmp(type, @encode(CGPoint)) == 0) {           //  "{CGPoint=dd}"  CGPoint
            CGPoint actual = (CGPoint)va_arg(v, CGPoint);
            obj = [NSValue value:&actual withObjCType:type];
            
        } else if (strcmp(type, @encode(CGSize)) == 0) {            //  "{CGSize=dd}"   CGSize
            CGSize actual = (CGSize)va_arg(v, CGSize);
            obj = [NSValue value:&actual withObjCType:type];
            
        } else if (strcmp(type, @encode(CGRect)) == 0) {            //  "{CGRect={CGPoint=dd}{CGSize=dd}}"  CGRect
            CGRect actual = (CGRect)va_arg(v, CGRect);
            obj = [NSValue value:&actual withObjCType:type];
            
        } else if (strcmp(type, @encode(UIEdgeInsets)) == 0) {      //  "{UIEdgeInsets=dddd}"   UIEdgeInsets
            UIEdgeInsets actual = (UIEdgeInsets)va_arg(v, UIEdgeInsets);
            obj = NSStringFromUIEdgeInsets(actual);
            
        } else if (strcmp(type, @encode(NSRange)) == 0) {           //  "{_NSRange=QQ}" NSRange
            NSRange actual = (NSRange)va_arg(v, NSRange);
            obj = NSStringFromRange(actual);
            
        } else if (strcmp(type, @encode(SEL)) == 0) {               //  ":"     SEL
            SEL actual = (SEL)va_arg(v, SEL);
            obj = [NSString stringWithFormat:@"SEL: %@", NSStringFromSelector(actual)];
            
        } else if (strcmp(type, @encode(Class)) == 0) {             //  "#"     Class
            Class actual = (Class)va_arg(v, Class);
            obj = NSStringFromClass(actual);
            
        } else if (strcmp(type, @encode(char *)) == 0) {            //  "*"     char *
            char * actual = (char *)va_arg(v, char *);
            obj = [NSString stringWithFormat:@"%s", actual];
            
        } else if (strcmp(type, @encode(double)) == 0) {            //  "d"     double
            double actual = (double)va_arg(v, double);
            obj = [NSNumber numberWithDouble:actual];
            
        } else if (strcmp(type, @encode(float)) == 0) {             //  "f"     float
            float actual = (float)va_arg(v, double);
            obj = [NSNumber numberWithFloat:actual];
            
        } else if (strcmp(type, @encode(int)) == 0) {               //  "i"     int
            int actual = (int)va_arg(v, int);
            obj = [NSNumber numberWithInt:actual];
            
        } else if (strcmp(type, @encode(long)) == 0) {              //  "q"     long
            long actual = (long)va_arg(v, long);
            obj = [NSNumber numberWithLong:actual];
            
        } else if (strcmp(type, @encode(long long)) == 0) {         //  "q"     long long
            long long actual = (long long)va_arg(v, long long);
            obj = [NSNumber numberWithLongLong:actual];
            
        } else if (strcmp(type, @encode(short)) == 0) {             //  "s"     short
            short actual = (short)va_arg(v, int);
            obj = [NSNumber numberWithShort:actual];
            
        } else if (strcmp(type, @encode(char)) == 0) {              //  "c"     char & BOOL(32bit)
            char actual = (char)va_arg(v, int);
            obj = [NSString stringWithFormat:@"%d char:%c", actual, actual];
            
        } else if (strcmp(type, @encode(bool)) == 0) {              //  "B"     bool & BOOL(64bit)
            bool actual = (bool)va_arg(v, int);
            obj = actual ? @"YES" : @"NO";
            
        } else if (strcmp(type, @encode(unsigned char)) == 0) {             //  "C"     unsigned char
            unsigned char actual = (unsigned char)va_arg(v, unsigned int);
            obj = [NSString stringWithFormat:@"%d unsigned char:%c", actual, actual];
            
        } else if (strcmp(type, @encode(unsigned int)) == 0) {              //  "I"     unsigned int
            unsigned int actual = (unsigned int)va_arg(v, unsigned int);
            obj = [NSNumber numberWithUnsignedInt:actual];
            
        } else if (strcmp(type, @encode(unsigned long)) == 0) {             //  "Q"     unsigned long
            unsigned long actual = (unsigned long)va_arg(v, unsigned long);
            obj = [NSNumber numberWithUnsignedLong:actual];
            
        } else if (strcmp(type, @encode(unsigned long long)) == 0) {        //  "Q"     unsigned long long
            unsigned long long actual = (unsigned long long)va_arg(v, unsigned long long);
            obj = [NSNumber numberWithUnsignedLongLong:actual];
            
        } else if (strcmp(type, @encode(unsigned short)) == 0) {            //  "S"     unsigned short
            unsigned short actual = (unsigned short)va_arg(v, unsigned int);
            obj = [NSNumber numberWithUnsignedShort:actual];
            
        } DoLogTypeExtension else {
            [result appendString:@"Error: unknown type"];
            break;
        }
        
        [result appendFormat:@"%@%@\n", ((void)(valueString), DoLogPrefix(i, valueString)), obj];
    }
    va_end(v);
    
    return [result copy];
}

static inline void _DoLog(NSString *str) {
    NSLog(@"\n%@", str);
}

static inline void _DoPrint(NSString *str) {
    printf("%s\n", str.UTF8String);
}

#pragma mark - Helper

#define DoStringify(VALUE) _DoStringify(VALUE)
#define _DoStringify(VALUE) # VALUE

#define DoConcat(A, B) _DoConcat(A, B)
#define _DoConcat(A, B) A ## B

// Return the number of arguments (up to twenty) provided to the macro.
#define DoArgCount(...) _DoArgCount(A, ##__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _DoArgCount(A, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, COUNT, ...) COUNT

// If the number of arguments is 0, return 0, otherwise return N.
#define DoArgCheck(...) _DoArgCheck(A, ##__VA_ARGS__, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 0)
#define _DoArgCheck(A, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, OBJ, ...) OBJ

// Each argument will be passed to the MACRO, the MACRO must be this form: MACRO(arg). Inspired by https://stackoverflow.com/questions/3136686/is-the-c99-preprocessor-turing-complete/10526117#10526117
#define DoForeach(MACRO, ...) DoConcat(_DoForeach, DoArgCheck(__VA_ARGS__)) (MACRO, ##__VA_ARGS__)
#define _DoForeach() DoForeach
#define _DoForeach0(MACRO)
#define _DoForeachN(MACRO, A, ...) MACRO(A) DoDefer(_DoForeach)() (MACRO, ##__VA_ARGS__)

#define DoEmpty()
#define DoDefer(ID) ID DoEmpty()

// For more scans
#define DoExpand(...)   _DoExpand1(_DoExpand1(_DoExpand1(__VA_ARGS__)))
#define _DoExpand1(...) _DoExpand2(_DoExpand2(_DoExpand2(__VA_ARGS__)))
#define _DoExpand2(...) _DoExpand3(_DoExpand3(_DoExpand3(__VA_ARGS__)))
#define _DoExpand3(...) __VA_ARGS__

#endif /* DoLog_h */
