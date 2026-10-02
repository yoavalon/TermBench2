import Foundation

func generateHashSequence(n: Int) -> [String] {
    var data = "initial_data"
    var hashes = [String]()
    for _ in 0..<n {
        data = data.sha256()
        hashes.append(data)
    }
    return hashes
}

extension String {
    func sha256() -> String {
        let data = self.data(using: .utf8)!
        var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &digest)
        }
        let hexString = digest.map { String(format: "%02x", $0) }.joined()
        return hexString
    }
}

func main() {
    let result = generateHashSequence(n: 10)
    for item in result {
        print(item)
    }
}

main()