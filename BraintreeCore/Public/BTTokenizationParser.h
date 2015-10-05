#import "BTJSON.h"
#import "BTTokenized.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// A JSON parser that parses `BTJSON` into concrete `BTTokenized` objects. It supports registration of
/// parsers at runtime.
///
/// @note `BTTokenizationParser` provides access to JSON parsing for different payment options
/// without introducing compile-time dependencies on payment option frameworks and their symbols.

@interface BTTokenizationParser : NSObject

/// The singleton instance
+ (instancetype)sharedParser;

/// An array of the tokenization types currently registered
@property (nonatomic, readonly, strong) NSArray<NSString *> *allTypes;

/// Indicates whether a tokenization type is currently registered
///
/// @param type The tokenization type string
- (BOOL)isTypeAvailable:(NSString *)type;

/// Registers a parsing block for a tokenization type.
///
/// @param type The tokenization type string
/// @param jsonParsingBlock The block to execute when `parseJSON:type:` is called for the tokenization type.
///        This block should return a `BTTokenized` object, or `nil` if the JSON cannot be parsed.
- (void)registerType:(NSString *)type withParsingBlock:(id <BTTokenized> _Nullable (^)(BTJSON *json))jsonParsingBlock;

/// Parses tokenized payment information that has been serialized to JSON, and returns a `BTTokenized` object.
/// The `BTTokenized` object is created by the JSON parsing block that has been registered for the tokenization
/// type.
///
/// If the `type` has not been registered, this method will attempt to read the nonce from the JSON and return
/// a basic object; if it fails, it will return `nil`.
///
/// @param json The tokenized payment info, serialized to JSON
/// @param type The registered type of the parsing block to use
/// @return A `BTTokenized` object, or `nil` if the tokenized payment info JSON does not contain a nonce
- (nullable id <BTTokenized>)parseJSON:(BTJSON *)json withParsingBlockForType:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
