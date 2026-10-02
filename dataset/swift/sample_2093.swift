import Foundation

class HashSimulator {
    var key: String
    var message: String

    init(key: String, message: String) {
        self.key = key
        self.message = message
    }

    func hashMessage() -> String {
        let data = message.data(using: .utf8)!
        let hash = Insecure.SHA256.hash(data: data)
        return hash.map { String(format: "%02hhx", $0) }.joined()
    }

    func hmacMessage() -> String {
        let keyData = key.data(using: .utf8)!
        let messageData = message.data(using: .utf8)!
        let hmac = Insecure.HMAC<Insecure.SHA256>.authenticationCode(for: messageData, using: keyData)
        return hmac.map { String(format: "%02hhx", $0) }.joined()
    }
}

class CipherSimulator {
    var data: String

    init(data: String) {
        self.data = data
    }

    func xorCipher(key: String) -> String {
        var result = ""
        for (x, y) in zip(data, key) {
            result.append(Character(UnicodeScalar(UInt8(x.ascii8bit) ^ UInt8(y.ascii8bit))!))
        }
        return result
    }

    func shiftCipher(shift: Int) -> String {
        var result = ""
        for x in data {
            let shifted = (UInt8(x.ascii8bit) + UInt8(shift)) % 256
            result.append(Character(UnicodeScalar(shifted)!))
        }
        return result
    }
}

class DataProcessor {
    var hashSimulator: HashSimulator
    var cipherSimulator: CipherSimulator

    init(hashSimulator: HashSimulator, cipherSimulator: CipherSimulator) {
        self.hashSimulator = hashSimulator
        self.cipherSimulator = cipherSimulator
    }

    func processData() -> (String, String, String) {
        let hashResult = hashSimulator.hashMessage()
        let hmacResult = hashSimulator.hmacMessage()
        let xorResult = cipherSimulator.xorCipher(key: hashResult.prefix(16).map { String($0) }.joined())
        let shiftResult = cipherSimulator.shiftCipher(shift: 5)
        return (hmacResult, xorResult, shiftResult)
    }
}

func main() {
    let key = Data.randomBytes(16).map { String(format: "%02hhx", $0) }.joined()
    let message = "SecureMessage"
    let hashSim = HashSimulator(key: key, message: message)
    let cipherSim = CipherSimulator(data: message)
    let dataProcessor = DataProcessor(hashSimulator: hashSim, cipherSimulator: cipherSim)
    let result = dataProcessor.processData()
    print(result)
}

main()