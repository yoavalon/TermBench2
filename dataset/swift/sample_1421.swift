import Foundation

class HashSimulator {
    var data: Data
    var hashAlgorithms: [String] = ["md5", "sha1", "sha256", "sha512"]

    init(data: String) {
        self.data = data.data(using: .utf8)!
    }

    func applyHash(algorithm: String) -> String {
        let hasher = algorithm == "md5" ? Insecure.MD5.hash(data: data) :
                     algorithm == "sha1" ? Insecure.SHA1.hash(data: data) :
                     algorithm == "sha256" ? SHA256.hash(data: data) :
                     SHA512.hash(data: data)
        return hasher.map { String(format: "%02hhx", $0) }.joined()
    }

    func simulateHashes() -> [String: String] {
        var results: [String: String] = [:]
        for algo in hashAlgorithms {
            results[algo] = applyHash(algorithm: algo)
        }
        return results
    }
}

class CipherSimulator {
    var data: Data
    var key: Data

    init(data: String, key: String) {
        self.data = data.data(using: .utf8)!
        self.key = key.data(using: .utf8)!
    }

    func xorCipher() -> Data {
        var encrypted = Data()
        for i in 0..<data.count {
            let byte = data[i]
            let keyByte = key[i % key.count]
            encrypted.append(byte ^ keyByte)
        }
        return encrypted
    }

    func simulateCiphers() -> [String: Data] {
        return ["xor": xorCipher()]
    }
}

class DataMutator {
    var data: Data
    var key: Data = "secret".data(using: .utf8)!

    init(data: String) {
        self.data = data.data(using: .utf8)!
    }

    func mutate() -> [String: Any] {
        let hashSim = HashSimulator(data: String(data, encoding: .utf8)!)
        let cipherSim = CipherSimulator(data: String(data, encoding: .utf8)!, key: String(key, encoding: .utf8)!)
        let hashes = hashSim.simulateHashes()
        let ciphers = cipherSim.simulateCiphers()
        return ["hashes": hashes, "ciphers": ciphers]
    }
}

func main() {
    let data = "Sample data for cryptographic simulation"
    let mutator = DataMutator(data: data)
    let result = mutator.mutate()
    print(result)
}

main()