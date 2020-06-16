//
//    Copyright (c) 2018-present, Square, Inc. All rights reserved.
//
//    Your use of this software is subject to the Square Developer Terms of
//    Service (https://squareup.com/legal/developers). This copyright notice shall
//    be included in all copies or substantial portions of the software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//    THE SOFTWARE.
//

#import <Foundation/Foundation.h>


@interface SQRDCardReceiptDetails : NSObject <NSCopying>

/**
 The Application Identifier (AID) is used to target an application on the card.
 
 For example, A0 00 00 00 25 01 09 01.
 */
@property (nonatomic, readonly, nullable) NSString *applicationIdentifier;

/**
 The mnemonic associated with the Application Identifier (AID).
 
 For example, AMERICAN EXPRESS.
 */
@property (nonatomic, readonly, nullable) NSString *applicationPreferredName;

/**
 A code returned by the card issuer.
 
 For example, 262921.
 */
@property (nonatomic, readonly, nullable) NSString *authorizationCode;

@end
