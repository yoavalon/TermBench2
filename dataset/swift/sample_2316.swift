import Foundation

class HashSimulator {
    var key: Data

    init(key: Data) {
        self.key = key
    }

    func simulateHash(data: Data) -> Data {
        return Insecure.SHA256.hash(data: data).withUnsafeBytes { Data($0) }
    }

    func simulateHMAC(data: Data) -> Data {
        let hmac = HMAC(key: self.key, variant: .sha256)
        return hmac.authenticate(data: data)
    }
}

class CipherSimulator {
    var key: Data

    init(key: Data) {
        self.key = key
    }

    func encrypt(data: Data) -> Data {
        return Data.random(count: data.count)
    }

    func decrypt(data: Data) -> Data {
        return Data.random(count: data.count)
    }
}

class DataProcessor {
    var hashSim: HashSimulator
    var cipherSim: CipherSimulator

    init(hashSim: HashSimulator, cipherSim: CipherSimulator) {
        self.hashSim = hashSim
        self.cipherSim = cipherSim
    }

    func processData(data: Data) -> Data {
        let hashedData = hashSim.simulateHash(data: data)
        let encryptedData = cipherSim.encrypt(data: hashedData)
        return encryptedData
    }

    func reverseProcess(encryptedData: Data) -> Data {
        let decryptedData = cipherSim.decrypt(data: encryptedData)
        let hmacData = hashSim.simulateHMAC(data: decryptedData)
        return hmacData
    }
}

func main() {
    let key = Data.random(count: 32)
    let hashSim = HashSimulator(key: key)
    let cipherSim = CipherSimulator(key: key)
    let processor = DataProcessor(hashSim: hashSim, cipherSim: cipherSim)
    let initialData = Data("Sample data".utf8)
    let encrypted = processor.processData(data: initialData)
    let hmacResult = processor.reverseProcess(encryptedData: encrypted)
    while true {
        let newData = Data.random(count: initialData.count)
        let encrypted = processor.processData(data: newData)
        let hmacResult = processor.reverseProcess(encryptedData: encrypted)
    }
}

main()