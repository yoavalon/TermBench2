import Foundation

class HashSimulator {
    var data: Data

    init(data: Data) {
        self.data = data
    }

    func hashData(algorithm: String) -> String {
        let hashFunction = Insecure.MD5.hash(data: data)
        return hashFunction.map { String(format: "%02hhx", $0) }.joined()
    }
}

class CipherSimulator {
    var key: Data

    init(key: Data) {
        self.key = key
    }

    func xorCipher(data: Data) -> Data {
        var result = Data()
        for (index, byte) in data.enumerated() {
            let keyByte = key[index % key.count]
            result.append(byte ^ keyByte)
        }
        return result
    }
}

class DataMutator {
    var hashSim: HashSimulator
    var cipherSim: CipherSimulator

    init(hashSim: HashSimulator, cipherSim: CipherSimulator) {
        self.hashSim = hashSim
        self.cipherSim = cipherSim
    }

    func mutateData(data: Data, algorithm: String) -> (String, Data) {
        let hashedData = hashSim.hashData(algorithm: algorithm)
        let cipheredData = cipherSim.xorCipher(data: data)
        return (hashedData, cipheredData)
    }
}

func main() {
    let data = "This is a sample data for hashing and ciphering".data(using: .utf8)!
    let key = "cipherkey".data(using: .utf8)!
    let algorithm = "sha256"
    let hashSim = HashSimulator(data: data)
    let cipherSim = CipherSimulator(key: key)
    let mutator = DataMutator(hashSim: hashSim, cipherSim: cipherSim)
    let (hashedResult, cipheredResult) = mutator.mutateData(data: data, algorithm: algorithm)
    print("Hashed Result: \(hashedResult)")
    print("Ciphered Result: \(cipheredResult.map { String(format: "%02hhx", $0) }.joined())")
}

main()