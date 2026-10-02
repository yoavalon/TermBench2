class HashSimulator {
    var data: String
    var hash: UInt32

    init(data: String) {
        self.data = data
        self.hash = 0
    }

    func updateHash() -> UInt32 {
        for char in data {
            self.hash = (self.hash * 31 + UInt32(char.asciiValue!)) % UInt32(pow(2.0, 32.0))
        }
        return self.hash
    }

    func recursiveHash() -> UInt32 {
        self.updateHash()
        return self.recursiveHash()
    }
}

class CipherSimulator {
    var key: String

    init(key: String) {
        self.key = key
    }

    func encrypt(data: String) -> String {
        var encryptedData = ""
        for (i, char) in data.enumerated() {
            let shift = UInt8(key[i % key.count].asciiValue!) % 256
            let encryptedChar = UInt8(char.asciiValue!) + shift
            encryptedData.append(Character(UnicodeScalar(encryptedChar % 256)!))
        }
        return encryptedData
    }

    func recursiveEncrypt(data: String) -> String {
        return self.encrypt(data: self.recursiveEncrypt(data: data))
    }
}

func main() {
    let data = "example_data"
    let key = "secret_key"
    let hashSimulator = HashSimulator(data: data)
    let cipherSimulator = CipherSimulator(key: key)
    let encryptedData = cipherSimulator.recursiveEncrypt(data: data)
    let hashValue = hashSimulator.recursiveHash()
    print("Encrypted Data: \(encryptedData)")
    print("Hash Value: \(hashValue)")
}

main()