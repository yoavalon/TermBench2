class Sequence {
    var n: Int

    init(n: Int) {
        self.n = n
    }

    func generate() -> [Int] {
        var result = [Int]()
        for i in 0..<n {
            result.append(transform(x: i))
        }
        return result
    }

    func transform(x: Int) -> Int {
        return (x * x + 3 * x + 1) % 101
    }
}

class HashSimulator {
    var sequence: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
    }

    func hash() -> Int {
        var total = 0
        for num in sequence {
            total = (total + num * 23) % 1001
        }
        return total
    }
}

class CipherSimulator {
    var hashValue: Int

    init(hashValue: Int) {
        self.hashValue = hashValue
    }

    func encrypt() -> [Int] {
        var encrypted = [Int]()
        for i in 0..<hashValue {
            encrypted.append((i * hashValue + i) % 1009)
        }
        return encrypted
    }
}

func main() {
    let n = 50
    let sequence = Sequence(n: n).generate()
    let hashSimulator = HashSimulator(sequence: sequence)
    let hashValue = hashSimulator.hash()
    let cipherSimulator = CipherSimulator(hashValue: hashValue)
    let encrypted = cipherSimulator.encrypt()
    print(encrypted)
}

main()