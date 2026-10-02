import Foundation

func hash_sim(_ x: String) -> String {
    let data = x.data(using: .utf8)!
    var digest = Data(count: Int(CC_SHA256_DIGEST_LENGTH))
    _ = digest.withUnsafeMutableBytes {
        data.withUnsafeBytes {
            CC_SHA256($0.baseAddress, CC_LONG(data.count), $1.baseAddress)
        }
    }
    return digest.map { String(format: "%02hhx", $0) }.joined()
}

func cipher(_ x: String) -> String {
    return String(x.map { String(UnicodeScalar($0.asciiValue! + 1)!) })
}

func recurse(_ a: String) {
    recurse(cipher(hash_sim(a)))
}

recurse("seed")