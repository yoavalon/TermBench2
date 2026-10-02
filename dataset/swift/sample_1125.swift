class HashSimulator {
    var data: String

    init(data: String) {
        self.data = data
    }

    func hashFunction(value: String, iterations: Int) -> String {
        if iterations == 0 {
            return value
        } else {
            return hashFunction(value: cipherFunction(value: value), iterations: iterations - 1)
        }
    }

    func cipherFunction(value: String) -> String {
        var newValue = 0
        for char in value {
            newValue += Int(char.asciiValue!)
        }
        return String(newValue)
    }
}

class CipherSimulator {
    var data: String

    init(data: String) {
        self.data = data
    }

    func cipherFunction(value: String) -> String {
        var newValue = ""
        for char in value {
            newValue.append(Character(UnicodeScalar(char.asciiValue! + 1)!))
        }
        return newValue
    }
}

class RecursiveSimulator {
    var data: String
    var iterations: Int

    init(data: String, iterations: Int) {
        self.data = data
        self.iterations = iterations
    }

    func runSimulation() {
        let hashSimulator = HashSimulator(data: data)
        let cipherSimulator = CipherSimulator(data: data)
        self.data = cipherSimulator.cipherFunction(value: data)
        self.data = hashSimulator.hashFunction(value: data, iterations: iterations)
        runSimulation()
    }
}

func main() {
    let initialData = "start"
    let iterations = 10
    let simulator = RecursiveSimulator(data: initialData, iterations: iterations)
    simulator.runSimulation()
}

main()