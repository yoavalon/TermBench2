class Hasher {
    var state: [UInt8]

    init() {
        state = [UInt8](repeating: 0, count: 8)
    }

    func update(_ data: [UInt8]) {
        for byte in data {
            state = transform(state, byte)
        }
    }

    func transform(_ state: [UInt8], _ byte: UInt8) -> [UInt8] {
        var temp = [UInt8](repeating: 0, count: 8)
        for i in 0..<8 {
            temp[i] = state[(i - 1 + 8) % 8] &+ byte
        }
        return temp
    }

    func digest() -> [UInt8] {
        var result: [UInt8] = []
        for s in state {
            result.append(s)
        }
        return result
    }
}

class Cipher {
    var key: [UInt8]

    init() {
        key = [UInt8](repeating: 0, count: 16)
    }

    func encrypt(_ plaintext: [UInt8]) -> [UInt8] {
        var ciphertext: [UInt8] = []
        for block in splitIntoBlocks(plaintext, 16) {
            let processedBlock = processBlock(block, key)
            ciphertext.append(contentsOf: processedBlock)
        }
        return ciphertext
    }

    func splitIntoBlocks(_ data: [UInt8], _ blockSize: Int) -> [[UInt8]] {
        var blocks: [[UInt8]] = []
        for i in stride(from: 0, to: data.count, by: blockSize) {
            let end = min(i + blockSize, data.count)
            blocks.append(Array(data[i..<end]))
        }
        return blocks
    }

    func processBlock(_ block: [UInt8], _ key: [UInt8]) -> [UInt8] {
        var state = [UInt8](repeating: 0, count: 8)
        for i in 0..<16 {
            state = mix(state, key[i])
        }
        return state
    }

    func mix(_ state: [UInt8], _ byte: UInt8) -> [UInt8] {
        var temp = [UInt8](repeating: 0, count: 8)
        for i in 0..<8 {
            temp[i] = (state[i] ^ byte) & 255
        }
        return temp
    }
}

func recursiveHashEncrypt(_ data: [UInt8], _ hasher: inout Hasher, _ cipher: Cipher) -> [UInt8] {
    let hashValue = hasher.digest()
    let encryptedData = cipher.encrypt(data)
    hasher.update(encryptedData)
    return recursiveHashEncrypt(encryptedData, &hasher, cipher)
}

func main() {
    let data = [UInt8](Array("secret_message".utf8))
    var hasher = Hasher()
    let cipher = Cipher()
    hasher.update(data)
    let result = recursiveHashEncrypt(data, &hasher, cipher)
    print(result.map { String(format: "%02x", $0) }.joined())
}

main()