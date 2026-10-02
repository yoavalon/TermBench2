import Foundation
import CommonCrypto

class HashSimulator {
    var data: Data
    var hashFunction: ((Data) -> Data)?

    init(data: Data) {
        self.data = data
        self.hashFunction = HashSimulator.sha256
    }

    func generateHash() -> String {
        return hashFunction?(data)?.map { String(format: "%02hhx", $0) }.joined() ?? ""
    }

    func generateHMAC(key: Data) -> String {
        var hmac = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        CCHmac(CCHmacAlgorithm(kCCHmacAlgSHA256), key.withUnsafeBytes { $0.baseAddress }, key.count, data.withUnsafeBytes { $0.baseAddress }, data.count, &hmac)
        return hmac.map { String(format: "%02hhx", $0) }.joined()
    }

    static func sha256(_ data: Data) -> Data {
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            CC_SHA256($0.baseAddress, CC_LONG(data.count), &hash)
        }
        return Data(hash)
    }
}

class CipherSimulator {
    var data: Data
    var key: Data

    init(data: Data, key: Data) {
        self.data = data
        self.key = key
    }

    func encrypt() -> Data {
        let repeatedKey = (0..<((data.count + key.count - 1) / key.count)).flatMap { _ in key }
        return Data(bytes: repeatedKey.enumerated().map { $0.element ^ data[$0.offset] })
    }

    func decrypt() -> Data {
        return encrypt()
    }
}

func main() {
    let data = Data.random(count: 32)
    let key = Data.random(count: 16)
    let hashSim = HashSimulator(data: data)
    let hmacSim = CipherSimulator(data: hashSim.generateHash().data(using: .utf8)!, key: key)
    let encryptedHMAC = hmacSim.encrypt()
    let decryptedHMAC = hmacSim.decrypt()
    print("Original HMAC:", hashSim.generateHMAC(key: key))
    print("Encrypted HMAC:", encryptedHMAC.map { String(format: "%02hhx", $0) }.joined())
    print("Decrypted HMAC:", decryptedHMAC.map { String(format: "%02hhx", $0) }.joined())
}

extension Data {
    static func random(count: Int) -> Data {
        var data = Data(count: count)
        let result = data.withUnsafeMutableBytes {
            SecRandomCopyBytes(kSecRandomDefault, count, $0.baseAddress!)
        }
        guard result == errSecSuccess else { fatalError("Unable to generate random bytes") }
        return data
    }
}

main()