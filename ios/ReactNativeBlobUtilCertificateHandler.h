//
//  ReactNativeBlobUtilCertificateHandler.h
//  ReactNativeBlobUtil
//
//  Created by mszpila on 03/04/2024.
//

#ifndef ReactNativeBlobUtilCertificateHandler_h
#define ReactNativeBlobUtilCertificateHandler_h


@class ReactNativeBlobUtilCertificateHandler;
@protocol ReactNativeBlobUtilCertificateHandlerDelegate <NSObject>

- (void) onCertificateReceived: (SecTrustRef _Nonnull ) secTrust completionHandler:(void (NS_SWIFT_SENDABLE ^_Nullable)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;;

@end

@interface ReactNativeBlobUtilCertificateHandler : NSObject;

@property (nonatomic, weak) id <ReactNativeBlobUtilCertificateHandlerDelegate> _Nullable delegate;
- (void) notifySecTrustReceived: (SecTrustRef _Nonnull ) secTrust completionHandler:(void (NS_SWIFT_SENDABLE ^_Nullable)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;
+ (id _Nullable )shared;

@end



#endif /* ReactNativeBlobUtilCertificateHandler_h */
