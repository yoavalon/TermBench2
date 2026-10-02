import Foundation

class DataProcessor {
    var data: String
    var hash: String
    var cipher: String

    init(data: String) {
        self.data = data
        self.hash = self.hash_data(data)
        self.cipher = self.cipher_data(data)
    }

    func hash_data(_ data: String) -> String {
        let data = data.data(using: .utf8)!
        let hash = SHA256.hash(data: data)
        return hash.map { String(format: "%02hhx", $0) }.joined()
    }

    func cipher_data(_ data: String) -> String {
        var shifted_data = ""
        for char in data {
            let shifted_char = Character(UnicodeScalar((char.asciiValue! + 3) % 256))
            shifted_data.append(shifted_char)
        }
        return shifted_data
    }

    func update_data(_ new_data: String) {
        self.data = new_data
        self.hash = self.hash_data(new_data)
        self.cipher = self.cipher_data(new_data)
    }
}

class DataSimulator {
    var processor: DataProcessor

    init(initial_data: String) {
        self.processor = DataProcessor(data: initial_data)
    }

    func simulate() {
        while true {
            let new_data = self.processor.cipher + self.processor.hash
            self.processor.update_data(new_data)
        }
    }
}

func main() {
    let initial_data = "seed"
    let simulator = DataSimulator(initial_data: initial_data)
    simulator.simulate()
}

main()