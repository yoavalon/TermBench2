import Foundation
import CommonCrypto

class HashSimulator {
    var data: String
    var key: String

    init(data: String, key: String) {
        self.data = data
        self.key = key
    }

    func hashData() -> String {
        let data = data.data(using: .utf8)!
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        CC_SHA256(data.bytes, CC_LONG(data.count), &hash)
        let hashString = hash.map { String(format: "%02x", $0) }.joined()
        return hashString
    }

    func hmacData() -> String {
        let data = data.data(using: .utf8)!
        let keyData = key.data(using: .utf8)!
        var hmac = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        CCHmac(CCHmacAlgorithm(kCCHmacAlgSHA256), keyData.bytes, keyData.count, data.bytes, data.count, &hmac)
        let hmacString = hmac.map { String(format: "%02x", $0) }.joined()
        return hmacString
    }
}

class CipherSimulator {
    var data: String
    var key: String

    init(data: String, key: String) {
        self.data = data
        self.key = key
    }

    func encrypt() -> String {
        var encryptedData = ""
        for (index, c) in data.enumerated() {
            let k = key[index % key.count]
            let encryptedChar = String(UnicodeScalar((c.asciiValue! + k.asciiValue!) % 256)!)
            encryptedData += encryptedChar
        }
        return encryptedData
    }

    func decrypt(encryptedData: String) -> String {
        var decryptedData = ""
        for (index, c) in encryptedData.enumerated() {
            let k = key[index % key.count]
            let decryptedChar = String(UnicodeScalar((c.asciiValue! - k.asciiValue!) % 256)!)
            decryptedData += decryptedChar
        }
        return decryptedData
    }
}

func main() {
    let data = "SecureData"
    let key = "SecretKey"
    let hashSim = HashSimulator(data: data, key: key)
    let cipherSim = CipherSimulator(data: data, key: key)
    let hashResult = hashSim.hashData()
    let hmacResult = hashSim.hmacData()
    let encryptedData = cipherSim.encrypt()
    print("Hash: \(hashResult)")
    print("HMAC: \(hmacResult)")
    print("Encrypted: \(encryptedData)")
    let decryptedData = cipherSim.decrypt(encryptedData: encryptedData)
    print("Decrypted: \(decryptedData)")
}

main()