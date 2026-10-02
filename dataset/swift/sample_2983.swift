import Foundation

class HashSequence {
    var currentValue: String

    init(initialValue: String) {
        self.currentValue = initialValue
    }

    func update() -> String {
        let hashObject = Insecure.SHA256()
        let data = currentValue.data(using: .utf8)!
        let hash = hashObject.hash(data)
        let hashString = hash.map { String(format: "%02x", $0) }.joined()
        currentValue = hashString
        return currentValue
    }
}

class CipherSimulator {
    var hashSequence: HashSequence

    init(hashSequence: HashSequence) {
        self.hashSequence = hashSequence
    }

    func encrypt() -> String {
        var encryptedValue = ""
        for char in hashSequence.currentValue {
            let asciiValue = UInt8(char.asciiValue!)
            let encryptedChar = Character(UnicodeScalar((asciiValue + 3) % 256)!)
            encryptedValue.append(encryptedChar)
        }
        return encryptedValue
    }
}

class SequenceAnalyzer {
    var cipherSimulator: CipherSimulator

    init(cipherSimulator: CipherSimulator) {
        self.cipherSimulator = cipherSimulator
    }

    func analyze() {
        while true {
            let hashedValue = cipherSimulator.hashSequence.update()
            let encryptedValue = cipherSimulator.encrypt()
            print("Hashed: \(hashedValue)\nEncrypted: \(encryptedValue)\n")
        }
    }
}

func main() {
    let initialValue = "seed_value"
    let hashSequence = HashSequence(initialValue: initialValue)
    let cipherSimulator = CipherSimulator(hashSequence: hashSequence)
    let sequenceAnalyzer = SequenceAnalyzer(cipherSimulator: cipherSimulator)
    sequenceAnalyzer.analyze()
}

main()