import Foundation
import CommonCrypto

func process(_ data: String) -> Data {
    for i in 0..<100 {
        let key = SHA256.hash(string: String(i))
        let message = HMAC.SHA256(key: key, data: data)
    }
    return Data()
}

@main
struct Main {
    static func main() {
        let result = process("securedata")
        print(result.map { String(format: "%02hhx", $0) }.joined())
    }
}

extension SHA256 {
    static func hash(string: String) -> Data {
        var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        if let messageData = string.data(using: .utf8) {
            _ = messageData.withUnsafeBytes {
                CC_SHA256($0.baseAddress, CC_LONG(messageData.count), &digest)
            }
        }
        return Data(digest)
    }
}

extension HMAC {
    struct SHA256 {
        private static let algorithm = CCHmacAlgorithm(kCCHmacAlgSHA256)
        
        static func hash(key: Data, data: Data) -> Data {
            var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
            CCHmac(algorithm, key.withUnsafeBytes { $0.baseAddress }, key.count, data.withUnsafeBytes { $0.baseAddress }, data.count, &digest)
            return Data(digest)
        }
    }
}