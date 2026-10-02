import Foundation

class HashSimulator {
    var key: String

    init(key: String) {
        self.key = key
    }

    func generateHash(data: String) -> String {
        let data = data.data(using: .utf8)!
        let hash = Insecure.SHA256.hash(data: data)
        return hash.map { String(format: "%02hhx", $0) }.joined()
    }

    func createHMAC(data: String) -> String {
        let keyData = key.data(using: .utf8)!
        let data = data.data(using: .utf8)!
        let hmac = HMAC<Insecure.SHA256>.authenticationCode(for: data, using: keyData)
        return hmac.map { String(format: "%02hhx", $0) }.joined()
    }
}

class CipherSimulator {
    var key: String

    init(key: String) {
        self.key = key
    }

    func encrypt(plaintext: String) -> String {
        return String(plaintext.enumerated().map { (i, c) in
            let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
            let encryptedChar = UnicodeScalar((c.asciiValue! + keyChar.asciiValue!) % 256)
            return Character(encryptedChar!)
        })
    }

    func decrypt(ciphertext: String) -> String {
        return String(ciphertext.enumerated().map { (i, c) in
            let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
            let decryptedChar = UnicodeScalar((c.asciiValue! - keyChar.asciiValue!) % 256)
            return Character(decryptedChar!)
        })
    }
}

class SequenceGenerator {
    var seed: UInt32

    init(seed: UInt32) {
        self.seed = seed
    }

    func generateSequence(length: Int) -> [UInt32] {
        var sequence: [UInt32] = []
        var current = seed
        for _ in 0..<length {
            sequence.append(current)
            current = (current * 1664525 + 1013904223) % (1 << 32)
        }
        return sequence
    }
}

func main() {
    let key = Data.randomBytes(count: 16).map { String(format: "%02hhx", $0) }.joined()
    let hashSim = HashSimulator(key: key)
    let cipherSim = CipherSimulator(key: key)
    let seqGen = SequenceGenerator(seed: 12345)
    while true {
        let data = "test_data"
        let hashValue = hashSim.generateHash(data: data)
        let hmacValue = hashSim.createHMAC(data: data)
        let encrypted = cipherSim.encrypt(plaintext: data)
        let decrypted = cipherSim.decrypt(ciphertext: encrypted)
        let sequence = seqGen.generateSequence(length: 10)
    }
}

main()