//
//  Copyright (c) 2018-present, Square, Inc. All rights reserved.
//
//  Your use of this software is subject to the Square Developer Terms of
//  Service (https://squareup.com/legal/developers). This copyright notice shall
//  be included in all copies or substantial portions of the software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

@import UIKit;
#import <SquareReaderSDK/SQRDErrorConstants.h>

@class SQRDStoreCustomerCardController;
@class SQRDCard;


/** The Store Customer Card controller error domain. */
extern NSString *_Nonnull const SQRDStoreCustomerCardControllerErrorDomain;

/** The types of errors that can occur when presenting a `SQRDStoreCustomerCardController`. */
SQRD_ERROR_ENUM(SQRDStoreCustomerCardControllerErrorDomain, SQRDStoreCustomerCardControllerError){
    /**
     `SQRDStoreCustomerCardController` was used in an unexpected or unsupported way.
     See `userInfo[SQRDErrorDebugCodeKey]` and `userInfo[SQRDErrorDebugMessageKey]` for more information.
     */
    SQRDStoreCustomerCardControllerErrorUsageError = 1,

    /** Reader SDK could not connect to the network. */
    SQRDStoreCustomerCardControllerErrorNoNetworkConnection,

    /** Reader SDK is not currently authorized. */
    SQRDStoreCustomerCardControllerErrorSDKNotAuthorized,

    /** The customer ID passed into the controller was invalid. */
    SQRDStoreCustomerCardControllerErrorInvalidCustomerID,
};

/**
 The delegate of a `SQRDStoreCustomerCardController` object must adopt the `SQRDStoreCustomerCardControllerDelegate` protocol.
 */
@protocol SQRDStoreCustomerCardControllerDelegate

/**
 Indicates that the Store Customer Card flow succeeded.
 
 @param storeCustomerCardController The Store Customer Card controller instance that finished.
 @param card The card stored by the controller.
 @note Remove the loading indicator from your UI when you receive `storeCustomerCardController:didFinishWithCard:`.
 */
- (void)storeCustomerCardController:(nonnull SQRDStoreCustomerCardController *)storeCustomerCardController didFinishWithCard:(nonnull SQRDCard *)card NS_SWIFT_NAME(storeCustomerCardController(_:didFinishWith:));

/**
 Indicates that the Store Customer Card flow failed.
 
 @param storeCustomerCardController The Store Customer Card controller instance that failed with an error.
 @param error An error in the `SQRDStoreCustomerCardControllerErrorDomain`.
 See `SQRDStoreCustomerCardControllerError` for possible error types.
 @note Remove the loading indicator from your UI when you receive `storeCustomerCardController:didFailWithError:`.
 */
- (void)storeCustomerCardController:(nonnull SQRDStoreCustomerCardController *)storeCustomerCardController didFailWithError:(nonnull NSError *)error NS_SWIFT_NAME(storeCustomerCardController(_:didFailWith:));

/**
 Indicates that the Store Customer Card flow was cancelled.

 @param storeCustomerCardController The Store Customer Card controller instance that was cancelled.
 @note Remove the loading indicator from your UI when you receive `storeCustomerCardControllerDidCancel:`.
 */
- (void)storeCustomerCardControllerDidCancel:(nonnull SQRDStoreCustomerCardController *)storeCustomerCardController;

@end

/**
 Lets the application use a Square Reader to store card information for use in later transactions when the card may not be present (also known as storing a card "on file" for a customer to use).

 The card information is stored on Square servers, not on the specific device running Reader SDK. This means cards cannot be saved on file when offline, and that saved cards for a customer are available from any device, keyed by customer ID.
 */
@interface SQRDStoreCustomerCardController : NSObject

/**
 Creates a new Store Customer Card controller.
 
 @param customerID The ID of an existing Customer object created using the [Customers API](https://docs.connect.squareup.com/api/connect/v2#navsection-customers).
 @param delegate The object that acts as the delegate of the Store Customer Card controller.
 */
- (nonnull instancetype)initWithCustomerID:(nonnull NSString *)customerID
                                  delegate:(nonnull id<SQRDStoreCustomerCardControllerDelegate>)delegate;

/**
 Presents a view controller for the Store Customer Card flow.
 
 This flow begins with a network call to validate the provided customer ID, which may take time depending on network conditions.  You should show a loading indicator before calling this method and remove it after receiving a success, failure, or cancellation callback.
 
 @param viewController The view controller from which the Store Customer Card flow should be modally presented.
 @note Reader SDK must be authorized to present the Store Customer Card flow.
 @note This method must be called from the main thread.
 @note Show a loading indicator in your UI before calling `presentFromViewController:`.
 */
- (void)presentFromViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(present(from:));

/**
 :nodoc:
 `init` is unavailable. Use `initWithCustomerID:delegate:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 `new` is unavailable. Use `initWithCustomerID:delegate:` instead.
 */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
