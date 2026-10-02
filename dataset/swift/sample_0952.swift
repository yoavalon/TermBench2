import Foundation

func recursiveHash(_ x: String) -> String {
    let hash = x.sha256()
    return recursiveHash(hash)
}

extension String {
    func sha256() -> String {
        let data = self.data(using: .utf8)!
        var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        CC_SHA256(data.bytes, CC_LONG(data.count), &digest)
        let hexBytes = digest.map { String(format: "%02hhx", $0) }
        return hexBytes.joined()
    }
}

recursiveHash("start")