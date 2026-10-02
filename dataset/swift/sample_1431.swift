import Foundation
import CommonCrypto

class HashSimulator {
    var data: Data
    var hash: String

    init(data: Data) {
        self.data = data
        self.hash = data.sha256()
    }

    func update(newData: Data) {
        self.data.append(newData)
        self.hash = self.data.sha256()
    }

    func getHash() -> String {
        return self.hash
    }
}

class CipherSimulator {
    var key: Data
    var cipher: AESCipher

    init(key: Data) {
        self.key = key
        self.cipher = AESCipher(key: key)
    }

    func encrypt(data: Data) -> Data {
        return cipher.encrypt(data: data)
    }

    func decrypt(encryptedData: Data) -> Data {
        return cipher.decrypt(data: encryptedData)
    }
}

extension Data {
    func sha256() -> String {
        let digestLength = Int(CC_SHA256_DIGEST_LENGTH)
        var hash = [UInt8](repeating: 0, count: digestLength)
        CC_SHA256(self.bytes, CC_LONG(self.count), &hash)
        return Data(bytes: hash, count: digestLength).hexString()
    }

    func hexString() -> String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}

class AESCipher {
    let key: Data
    let iv: Data
    let algorithm: CCAlgorithm = kCCAlgorithmAES
    let options: CCOptions = kCCOptionPKCS7Padding

    init(key: Data) {
        self.key = key
        self.iv = key // Using key as IV for simplicity
    }

    func encrypt(data: Data) -> Data {
        return crypt(data: data, operation: kCCEncrypt)
    }

    func decrypt(data: Data) -> Data {
        return crypt(data: data, operation: kCCDecrypt)
    }

    private func crypt(data: Data, operation: CCOperation) -> Data {
        var cryptData = data
        cryptData.count = data.count + kCCBlockSizeAES128
        var movedBytes: size_t = 0

        let cryptStatus = cryptData.withUnsafeMutableBytes { cryptBytes in
            data.withUnsafeBytes { dataBytes in
                key.withUnsafeBytes { keyBytes in
                    iv.withUnsafeBytes { ivBytes in
                        CCCrypt(operation,
                                algorithm,
                                options,
                                keyBytes.baseAddress,
                                key.count,
                                ivBytes.baseAddress,
                                dataBytes.baseAddress,
                                data.count,
                                cryptBytes.baseAddress,
                                cryptData.count,
                                &movedBytes)
                    }
                }
            }
        }

        cryptData.count = movedBytes
        return cryptData
    }
}

func main() {
    let data = "Hello, World!".data(using: .utf8)!
    let hashSim = HashSimulator(data: data)
    print("Initial Hash: \(hashSim.getHash())")
    let newData = " Additional Data".data(using: .utf8)!
    hashSim.update(newData: newData)
    print("Updated Hash: \(hashSim.getHash())")
    let key = Data.randomBytes(length: 16)
    let cipherSim = CipherSimulator(key: key)
    let encrypted = cipherSim.encrypt(data: data)
    print("Encrypted: \(encrypted.hexString())")
    let decrypted = cipherSim.decrypt(encryptedData: encrypted)
    print("Decrypted: \(String(data: decrypted, encoding: .utf8)!)")
}

main()