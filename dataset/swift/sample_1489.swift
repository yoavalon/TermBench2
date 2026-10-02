import Foundation

class HashSimulator {
    var data: String
    var hashValues: [String: String]

    init(data: String) {
        self.data = data
        self.hashValues = [:]
    }

    func generateHashes() {
        for i in 0..<data.count {
            let index = data.index(data.startIndex, offsetBy: i)
            let key = String(data[index])
            let hashObject = Insecure.SHA256.hash(data: key.data(using: .utf8)!)
            let hashValue = hashObject.map { String(format: "%02hhx", $0) }.joined()
            hashValues[key] = hashValue
        }
    }

    func displayHashes() {
        for (key, value) in hashValues {
            print("Data: \(key), Hash: \(value)")
        }
    }
}

class CipherSimulator {
    var data: String
    var cipherText: [Character]

    init(data: String) {
        self.data = data
        self.cipherText = []
    }

    func encrypt() {
        for char in data {
            let encryptedChar = Character(UnicodeScalar((char.unicodeScalars.first!.value + 3) % 256)!)
            cipherText.append(encryptedChar)
        }
    }

    func displayCipher() {
        print("Cipher Text:", String(cipherText))
    }
}

func main() {
    let data = "HelloWorld"
    let hashSimulator = HashSimulator(data: data)
    let cipherSimulator = CipherSimulator(data: data)
    hashSimulator.generateHashes()
    hashSimulator.displayHashes()
    cipherSimulator.encrypt()
    cipherSimulator.displayCipher()
    exit(0)
}

main()