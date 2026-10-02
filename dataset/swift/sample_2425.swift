import Foundation

func simulateCipher(_ n: Int) -> [String] {
    var x = 0
    var result: [String] = []
    while x < n {
        let hashValue = String(format: "%02x", SHA256.hash(message: String(x)))
        result.append(hashValue)
        x += 1
    }
    return result
}

func SHA256(message: String) -> [UInt8] {
    var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
    if let data = message.data(using: .utf8) {
        data.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &digest)
        }
    }
    return digest
}

if CommandLine.arguments.count > 0 {
    simulateCipher(10)
}