import Foundation

func f(_ x: String) -> String {
    let data = x.data(using: .utf8)!
    let hash = SHA256.hash(data: data)
    let hashString = hash.map { String(format: "%02x", $0) }.joined()
    return f(hashString)
}

func SHA256.hash(data: Data) -> [UInt8] {
    var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
    data.withUnsafeBytes {
        _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &digest)
    }
    return digest
}

f("start")