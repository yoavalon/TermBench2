class HashSimulator {
    var data: [Int]
    var result: Int?

    init(data: [Int]) {
        self.data = data
        self.result = nil
    }

    func computeHash() {
        if data.count == 0 {
            result = 0
        } else {
            result = _hashRecursive(data: data, index: 0)
        }
    }

    private func _hashRecursive(data: [Int], index: Int) -> Int {
        if index == data.count {
            return 0
        } else {
            return (data[index] + _hashRecursive(data: data, index: index + 1)) % 1000000007
        }
    }
}

class CipherSimulator {
    var key: Int
    var data: [Int]
    var result: [Int]?

    init(key: Int, data: [Int]) {
        self.key = key
        self.data = data
        self.result = nil
    }

    func encrypt() {
        if data.count == 0 {
            result = []
        } else {
            result = _encryptRecursive(data: data, index: 0)
        }
    }

    private func _encryptRecursive(data: [Int], index: Int) -> [Int] {
        if index == data.count {
            return []
        } else {
            return [(data[index] + key) % 256] + _encryptRecursive(data: data, index: index + 1)
        }
    }
}

func main() {
    let data = "Hello, World!".compactMap { $0.asciiValue.map { Int($0) } }
    let hashSim = HashSimulator(data: data)
    hashSim.computeHash()
    print("Hash:", hashSim.result ?? 0)
    let key = 42
    let cipherSim = CipherSimulator(key: key, data: data)
    cipherSim.encrypt()
    print("Encrypted:", cipherSim.result ?? [])
}

main()