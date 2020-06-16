//
//	Copyright (c) 2018-present, Square, Inc. All rights reserved.
//
//	Your use of this software is subject to the Square Developer Terms of
//	Service (https://squareup.com/legal/developers). This copyright notice shall
//	be included in all copies or substantial portions of the software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//	THE SOFTWARE.
//

@import Foundation;

@class SQRDMoney;
@class SQRDTipSettings;

/**
 The payment types an application may accept during checkout in addition to payments via Square Readers.
 */
typedef NS_OPTIONS(NSUInteger, SQRDAdditionalPaymentTypes) {
    /** Manually typed-in card payments. */
    SQRDAdditionalPaymentTypeManualCardEntry = 1 << 0,

    /** Cash payments. Useful for testing. */
    SQRDAdditionalPaymentTypeCash = 1 << 1,

    /** Check, third-party gift cards, and other payment types. */
    SQRDAdditionalPaymentTypeOther = 1 << 2,
};

/**
 Parameters for SQRDCheckoutController.
 
 Default values:
 - `note`: `nil`
 - `additionalPaymentTypes`: `[]`
 - `tipSettings`: `nil`
 - `skipReceipt`: `false`
 - `collectSignature`: `false`
 - `allowSplitTender`: `false`
 - `delayCapture`: `false`
 */
@interface SQRDCheckoutParameters : NSObject <NSCopying>

/**
 Create a `SQRDCheckoutParameters` with default values.
 @param amountMoney The charge amount.
 */
- (nonnull instancetype)initWithAmountMoney:(nonnull SQRDMoney *)amountMoney;

/**
 The amount of money to charge in the checkout flow.
 */
@property (nonatomic, readonly, nonnull) SQRDMoney *amountMoney;

/**
 An optional note to associate with the transaction.
 
 This note will be included in the `itemizations` field of `Payment` objects returned by
 the List Payments and Retrieve Payment endpoints of the [Square Connect v1 API]
 (https://docs.connect.squareup.com/api/connect/v1#datatype-paymentitemization).
 
 It is also included on Square digital receipts.
 */
@property (nonatomic, copy, nullable) NSString *note;

/**
 A set of payment types accepted during the checkout flow in addition to payments via Square Readers.
 For example, manually entered cards and cash.
 Defaults to an empty set.
 */
@property (nonatomic, assign) SQRDAdditionalPaymentTypes additionalPaymentTypes;

/**
 Configures tipping behavior of the checkout flow.
 
 When `tipSettings` is `nil`, tipping is disabled.
 Defaults to `nil`.
 */
@property (nonatomic, copy, nullable) SQRDTipSettings *tipSettings;

/**
 Indicates that the digital receipt options screen should not be displayed during checkout.
 
 `skipReceipt` does not override receipt options previously set by the customer. Square
 will always send digital receipts to customers who have opted-in to automatic receipts.
 
 Defaults to `false`.
 */
@property (nonatomic, assign) BOOL skipReceipt;

/**
 Indicates that signatures should be collected during checkout.
 
 When `true`, the signature screen will be displayed during checkout.
 Defaults to `false`.
 */
@property (nonatomic, assign) BOOL collectSignature;

/**
 Indicates that the transaction may be split into multiple tenders during the checkout flow.
 
 Defaults to `false`.
 */
@property (nonatomic, assign) BOOL allowSplitTender;

/**
 When `true`, if checkout completes successfully, the SDK will only authorize,but not
 capture any card payments. You can then use the Square Connect CaptureTransaction endpoint
 to capture the card payments at a later time.
 
 Setting `delayCapture` to `true` will skip the receipt, tipping, and signature
 screens, and the following parameters will be ignored:
 - `tipSettings`
 - `skipReceipt`
 - `collectSignature`
 
 Defaults to `false`. By default, the SDK will immediately capture all card payments.
 */
@property (nonatomic, assign, readwrite) BOOL delayCapture;

#pragma mark - Deprecated

/**
 @warning Deprecated. Use `collectSignature` instead. This property is a no-op and will be removed in a future major release.

 Indicates that signature collection is required during checkout.
 
 When `false`, the signature screen will only be displayed when required.
 Defaults to `true`.

 @see `collectSignature`  
 */
@property (nonatomic, assign) BOOL alwaysRequireSignature DEPRECATED_MSG_ATTRIBUTE("Use collectSignature instead. alwaysRequireSignature will be removed in a future major release.");

/**
 :nodoc:
 `init` is unavailable. Use `initWithAmountMoney:` instead.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

/**
 :nodoc:
 `new` is unavailable. Use `initWithAmountMoney:` instead.
 */
+ (nonnull instancetype) new NS_UNAVAILABLE;

@end
