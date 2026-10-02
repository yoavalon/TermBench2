import Foundation

class HashFunction {
    var data: [UInt8]
    var hashValue: Int

    init(data: [UInt8]) {
        self.data = data
        self.hashValue = 0
    }

    func update() -> HashFunction {
        for byte in data {
            self.hashValue = self.hashValue * 33 ^ Int(byte)
        }
        return self
    }

    func digest() -> Int {
        return self.hashValue
    }
}

class CipherSimulator {
    var key: [UInt8]
    var data: [UInt8]
    var encryptedData: [UInt8]

    init(key: [UInt8], data: [UInt8]) {
        self.key = key
        self.data = data
        self.encryptedData = [UInt8](repeating: 0, count: data.count)
    }

    func encrypt(index: Int = 0) -> CipherSimulator {
        if index >= data.count {
            return self
        }
        self.encryptedData[index] = data[index] ^ key[index % key.count]
        self.encrypt(index: index + 1)
        return self
    }

    func getEncryptedData() -> [UInt8] {
        return self.encryptedData
    }
}

func main() {
    let originalData = Array("Hello, world!".utf8)
    let hashFunction = HashFunction(data: originalData)
    hashFunction.update()
    let hashValue = hashFunction.digest()
    let key = Array("secret".utf8)
    let cipherSimulator = CipherSimulator(key: key, data: originalData)
    cipherSimulator.encrypt()
    let encryptedData = cipherSimulator.getEncryptedData()
    print("Hash Value: \(hashValue)")
    print("Encrypted Data: \(encryptedData.map { String(format: "%02x", $0) }.joined())")
}

main()