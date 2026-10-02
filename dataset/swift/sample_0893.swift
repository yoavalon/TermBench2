import Foundation

class HashSimulator {
    var data: String
    var depth: Int
    var current_depth: Int

    init(data: String, depth: Int) {
        self.data = data
        self.depth = depth
        self.current_depth = 0
    }

    func hash_data() -> String {
        let data = self.data.data(using: .utf8)!
        let hash = SHA256.hash(data: data)
        return hash.map { String(format: "%02x", $0) }.joined()
    }

    func recursive_hash() -> String {
        if self.current_depth >= self.depth {
            return self.hash_data()
        } else {
            self.current_depth += 1
            self.data = self.hash_data()
            return self.recursive_hash()
        }
    }
}

class CipherSimulator {
    var key: String
    var rounds: Int
    var current_round: Int

    init(key: String, rounds: Int) {
        self.key = key
        self.rounds = rounds
        self.current_round = 0
    }

    func simple_cipher(data: String) -> String {
        return String(data.map { (char: Character) -> Character in
            let charValue = char.asciiValue!
            let keyValue = key.first!.asciiValue!
            let newValue = (charValue + keyValue) % 256
            return Character(UnicodeScalar(newValue)!)
        })
    }

    func recursive_cipher(data: String) -> String {
        if self.current_round >= self.rounds {
            return data
        } else {
            self.current_round += 1
            let newData = simple_cipher(data: data)
            return recursive_cipher(data: newData)
        }
    }
}

func main() {
    let initial_data = "SecureData"
    let hash_depth = 5
    let cipher_rounds = 3
    let key = "Secret"
    let hash_simulator = HashSimulator(data: initial_data, depth: hash_depth)
    let hashed_data = hash_simulator.recursive_hash()
    let cipher_simulator = CipherSimulator(key: key, rounds: cipher_rounds)
    let encrypted_data = cipher_simulator.recursive_cipher(data: hashed_data)
    print(encrypted_data)
}

main()