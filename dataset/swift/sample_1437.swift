import Foundation
import CommonCrypto

class HashSimulator {
    var data: Data

    init(data: Data) {
        self.data = data
    }

    func computeHash(algorithm: String = "SHA256") -> String {
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &hash)
        }
        return hash.map { String(format: "%02x", $0) }.joined()
    }

    func computeHMAC(key: String, algorithm: String = "SHA256") -> String {
        let keyData = key.data(using: .utf8)!
        let hmac = NSMutableData(length: Int(CC_SHA256_DIGEST_LENGTH))!
        CCHmac(CCHmacAlgorithm(kCCHmacAlgSHA256), keyData.bytes, keyData.count, data.bytes, data.count, hmac.mutableBytes)
        return hmac.map { String(format: "%02x", $0) }.joined()
    }
}

class CipherSimulator {
    var data: Data

    init(data: Data) {
        self.data = data
    }

    func xorCipher(key: UInt8) -> Data {
        return data.map { $0 ^ key }
    }

    func caesarCipher(shift: Int) -> Data {
        return data.map { b -> UInt8 in
            if b >= 65 && b <= 90 {
                return UInt8((b - 65 + UInt8(shift)) % 26 + 65)
            } else {
                return b
            }
        }
    }
}

func dataMutations() {
    let data = Data.random(count: 32)
    let hashSimulator = HashSimulator(data: data)
    let cipherSimulator = CipherSimulator(data: data)
    let hashResult = hashSimulator.computeHash()
    let hmacResult = hashSimulator.computeHMAC(key: "secret_key")
    let xorResult = cipherSimulator.xorCipher(key: 170)
    let caesarResult = cipherSimulator.caesarCipher(shift: 3)
    print("Hash: \(hashResult)")
    print("HMAC: \(hmacResult)")
    print("XOR Cipher: \(xorResult.map { String(format: "%02x", $0) }.joined())")
    print("Caesar Cipher: \(caesarResult.map { String(format: "%02x", $0) }.joined())")
}

dataMutations()