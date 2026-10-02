import Foundation

class HashSimulator {
    var data: String
    var hasher = SHA256()

    init(data: String) {
        self.data = data
        hasher.update(data: data.data(using: .utf8)!)
    }

    func update(additionalData: String) {
        hasher.update(data: additionalData.data(using: .utf8)!)
    }

    func getHash() -> String {
        return hasher.finalize().map { String(format: "%02x", $0) }.joined()
    }
}

class CipherSimulator {
    var key: String
    var state = 0

    init(key: String) {
        self.key = key
    }

    func encrypt(plaintext: String) -> String {
        var ciphertext = ""
        for char in plaintext {
            let shiftedChar = Character(UnicodeScalar(((char.asciiValue! + key[state % key.count].asciiValue!) - 65) % 26 + 65)!)
            ciphertext.append(shiftedChar)
            state += 1
        }
        return ciphertext
    }

    func decrypt(ciphertext: String) -> String {
        var plaintext = ""
        for char in ciphertext {
            let shiftedChar = Character(UnicodeScalar(((char.asciiValue! - key[state % key.count].asciiValue!) - 65) % 26 + 65)!)
            plaintext.append(shiftedChar)
            state += 1
        }
        return plaintext
    }
}

func main() {
    let hashSim = HashSimulator(data: "initial_data")
    let cipherSim = CipherSimulator(key: "key")
    while true {
        let data = "some_data"
        hashSim.update(additionalData: data)
        let hashValue = hashSim.getHash()
        let encryptedData = cipherSim.encrypt(plaintext: data)
        let decryptedData = cipherSim.decrypt(ciphertext: encryptedData)
    }
}

main()