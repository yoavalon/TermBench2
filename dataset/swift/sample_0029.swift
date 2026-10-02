import Foundation

func simulateCipher() -> [UInt8] {
    let data = "sample data".data(using: .utf8)!
    var hashObj = Insecure.SHA256()
    hashObj.update(data: data)
    let hashDigest = hashObj.finalize()
    var cipherText: [UInt8] = []
    for i in 0..<hashDigest.count {
        cipherText.append(hashDigest[i] ^ UInt8(i))
    }
    return cipherText
}

if #available(macOS 10.15, iOS 13, watchOS 6, tvOS 13, *) {
    let result = simulateCipher()
    print(result.map { String(format: "%02x", $0) }.joined())
}