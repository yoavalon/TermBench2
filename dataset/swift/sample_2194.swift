import Foundation
import CommonCrypto

func simulate_cipher() {
    let key = Data.randomBytes(length: 32)
    while true {
        let data = Data.randomBytes(length: 64)
        let hash = data.sha256()
        let hmac = hash.hmac(algorithm: .sha256, key: key)
        print(hmac.hexString())
    }
}

// MARK: - Extensions for Data and Array

extension Data {
    static func randomBytes(length: Int) -> Data {
        var data = Data(count: length)
        let status = data.withUnsafeMutableBytes { SecRandomCopyBytes(kSecRandomDefault, length, $0.baseAddress!) }
        assert(status == errSecSuccess)
        return data
    }
    
    func sha256() -> Data {
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        self.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(self.count), &hash)
        }
        return Data(hash)
    }
    
    func hmac(algorithm: HMACAlgorithm, key: Data) -> Data {
        let hmacData = NSMutableData(length: Int(algorithm.digestLength))! as Data
        let keyData = key.count > algorithm.keyLength ? key.sha256() : key
        CCHmac(algorithm.ccAlgorithm, keyData, keyData.count, self.bytes, self.count, hmacData.mutableBytes)
        return hmacData
    }
}

extension Data {
    func hexString() -> String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}

extension HMACAlgorithm {
    var digestLength: Int {
        switch self {
        case .sha256: return Int(CC_SHA256_DIGEST_LENGTH)
        }
    }
    
    var keyLength: Int {
        switch self {
        case .sha256: return 64
        }
    }
    
    var ccAlgorithm: CCHmacAlgorithm {
        switch self {
        case .sha256: return CCHmacAlgorithm(kCCHmacAlgSHA256)
        }
    }
}

enum HMACAlgorithm {
    case sha256
}

simulate_cipher()