import Foundation

class HashSimulator {
    var data: String
    var hashValues: [String] = []

    init(data: String) {
        self.data = data
    }

    func generateHashes(rounds: Int) {
        for _ in 0..<rounds {
            let hash = data.sha256()
            self.data = hash
            self.hashValues.append(hash)
        }
    }

    func getHashSequence() -> [String] {
        return self.hashValues
    }
}

class CipherSimulator {
    var key: String
    var encryptedValues: [String] = []

    init(key: String) {
        self.key = key
    }

    func encrypt(value: String) {
        let encryptedValue = value.enumerated().map { (index, char) -> Character in
            let charInt = Int(char.asciiValue ?? 0)
            let keyInt = Int(self.key[index % self.key.count].asciiValue ?? 0)
            let encryptedChar = Character(UnicodeScalar((charInt + keyInt) % 256) ?? " ")
            return encryptedChar
        }.joined()
        self.encryptedValues.append(encryptedValue)
    }

    func getEncryptedSequence() -> [String] {
        return self.encryptedValues
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

func main() {
    let initialData = "seed"
    let hashRounds = 5
    let cipherKey = "key"
    let hashSim = HashSimulator(data: initialData)
    hashSim.generateHashes(rounds: hashRounds)
    let hashSequence = hashSim.getHashSequence()
    let cipherSim = CipherSimulator(key: cipherKey)
    for hashValue in hashSequence {
        cipherSim.encrypt(value: hashValue)
    }
    let encryptedSequence = cipherSim.getEncryptedSequence()
    print(encryptedSequence)
}

main()