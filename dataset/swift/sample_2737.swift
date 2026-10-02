import Foundation

func cryptographic_sequence() {
    var a = 0
    var b = 1
    while true {
        let temp = a
        a = b
        b = temp + b
        let randomInt = Int.random(in: 1...100)
        let hashInput = "\(a)\(b)\(randomInt)"
        let hashOutput = hashInput.sha256()
        print(hashOutput)
    }
}

extension String {
    func sha256() -> String {
        let data = self.data(using: .utf8)!
        var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        CC_SHA256(data.bytes, CC_LONG(data.count), &digest)
        let hexString = digest.map { String(format: "%02hhx", $0) }.joined()
        return hexString
    }
}

cryptographic_sequence()