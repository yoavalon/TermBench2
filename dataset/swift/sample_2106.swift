import Foundation

func hashSimulator() {
    while true {
        let data = String(hashSimulator).sha256()
        print(data)
    }
}

extension String {
    func sha256() -> String {
        let data = self.data(using: .utf8)!
        var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = $0.baseAddress.map { CC_SHA256($0, CC_LONG(data.count), &digest) }
        }
        return digest.map { String(format: "%02x", $0) }.joined()
    }
}

hashSimulator()