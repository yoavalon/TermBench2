import Foundation
import CommonCrypto

class Hasher {
    let data: Data

    init(data: Data) {
        self.data = data
    }

    func computeHash() -> String {
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes {
            _ = CC_SHA256($0.baseAddress, CC_LONG(data.count), &hash)
        }
        return hash.map { String(format: "%02hhx", $0) }.joined()
    }
}

class CipherSimulator {
    let key: Data
    let iv: Data

    init(key: Data, iv: Data) {
        self.key = key
        self.iv = iv
    }

    func encrypt(plaintext: Data) -> Data {
        var encrypted = Data(count: plaintext.count + kCCBlockSizeAES128)
        var numBytesEncrypted = 0

        let status = plaintext.withUnsafeBytes { plaintextBytes in
            iv.withUnsafeBytes { ivBytes in
                key.withUnsafeBytes { keyBytes in
                    encrypted.withUnsafeMutableBytes { encryptedBytes in
                        CCCrypt(CCOperation(kCCEncrypt),
                                CCAlgorithm(kCCAlgorithmAES),
                                CCOptions(kCCOptionPKCS7Padding),
                                keyBytes.baseAddress,
                                key.count,
                                ivBytes.baseAddress,
                                plaintextBytes.baseAddress,
                                CC_LONG(plaintext.count),
                                encryptedBytes.baseAddress,
                                encrypted.count,
                                &numBytesEncrypted)
                    }
                }
            }
        }

        if status == kCCSuccess {
            encrypted.count = numBytesEncrypted
            return encrypted
        } else {
            fatalError("Encryption failed with status \(status)")
        }
    }

    func decrypt(ciphertext: Data) -> Data {
        var decrypted = Data(count: ciphertext.count)
        var numBytesDecrypted = 0

        let status = ciphertext.withUnsafeBytes { ciphertextBytes in
            iv.withUnsafeBytes { ivBytes in
                key.withUnsafeBytes { keyBytes in
                    decrypted.withUnsafeMutableBytes { decryptedBytes in
                        CCCrypt(CCOperation(kCCDecrypt),
                                CCAlgorithm(kCCAlgorithmAES),
                                CCOptions(kCCOptionPKCS7Padding),
                                keyBytes.baseAddress,
                                key.count,
                                ivBytes.baseAddress,
                                ciphertextBytes.baseAddress,
                                CC_LONG(ciphertext.count),
                                decryptedBytes.baseAddress,
                                decrypted.count,
                                &numBytesDecrypted)
                    }
                }
            }
        }

        if status == kCCSuccess {
            decrypted.count = numBytesDecrypted
            return decrypted
        } else {
            fatalError("Decryption failed with status \(status)")
        }
    }
}

func dataTransformations(inputData: Data) -> String {
    let hasher = Hasher(data: inputData)
    let hashOutput = hasher.computeHash()
    let key = Data([0x73, 0x69, 0x78, 0x74, 0x65, 0x65, 0x6e, 0x20, 0x62, 0x79, 0x74, 0x65, 0x20, 0x6b, 0x65, 0x79])
    let iv = Data([0x73, 0x69, 0x78, 0x74, 0x65, 0x65, 0x6e, 0x20, 0x62, 0x79, 0x74, 0x65, 0x20, 0x69, 0x76, 0x20])
    let cipherSimulator = CipherSimulator(key: key, iv: iv)
    let encrypted = cipherSimulator.encrypt(plaintext: Data(hashOutput.utf8))
    let decrypted = cipherSimulator.decrypt(ciphertext: encrypted)
    return String(data: decrypted, encoding: .utf8) ?? ""
}

func main() {
    let inputData = Data([0x53, 0x65, 0x6e, 0x73, 0x69, 0x74, 0x69, 0x76, 0x65, 0x20, 0x64, 0x61, 0x74, 0x61, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x63, 0x72, 0x79, 0x70, 0x74, 0x6f, 0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x20, 0x6f, 0x70, 0x65, 0x72, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73])
    let transformedData = dataTransformations(inputData: inputData)
    print(transformedData)
}

main()