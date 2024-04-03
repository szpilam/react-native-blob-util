//
//  ReactNativeBlobUtilCertificateHandler.m
//  ReactNativeBlobUtil
//
//  Created by mszpila on 03/04/2024.
//

#import <Foundation/Foundation.h>
#import "ReactNativeBlobUtilCertificateHandler.h"

@implementation ReactNativeBlobUtilCertificateHandler : NSObject

@synthesize delegate;

static ReactNativeBlobUtilCertificateHandler *_shared = nil;


+ (id) shared {
    
    @synchronized ([ReactNativeBlobUtilCertificateHandler class]) {
        if (!_shared) {
            _shared = [[self alloc] init];
        }
        return _shared;
    }
}

- (void) notifySecTrustReceived:(SecTrustRef)secTrust completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable credantial))completionHandler {
    [delegate onCertificateReceived:secTrust completionHandler:completionHandler];
}

@end

