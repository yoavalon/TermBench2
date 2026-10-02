class HashSimulator {
    var data: String
    var hash: Int

    init(data: String) {
        self.data = data
        self.hash = 0
    }

    func hash_step(index: Int) -> Int {
        if index >= data.count {
            return hash
        }
        let char = data[data.index(data.startIndex, offsetBy: index)]
        hash = (hash + Int(char.asciiValue!) * (index + 1)) % 1000000007
        return hash_step(index: index + 1)
    }

    func compute_hash() -> Int {
        return hash_step(index: 0)
    }
}

class CipherSimulator {
    var key: String
    var text: String

    init(key: String, text: String) {
        self.key = key
        self.text = text
    }

    func cipher_step(index: Int, result: String) -> String {
        if index >= text.count {
            return result
        }
        let char = text[text.index(text.startIndex, offsetBy: index)]
        let shifted = (Int(char.asciiValue!) + Int(key[key.index(key.startIndex, offsetBy: index % key.count)].asciiValue!)) % 256
        let newResult = result + String(UnicodeScalar(shifted)!)
        return cipher_step(index: index + 1, result: newResult)
    }

    func encrypt() -> String {
        return cipher_step(index: 0, result: "")
    }
}

func main() {
    let data = "SecureData2023"
    let hash_sim = HashSimulator(data: data)
    let computed_hash = hash_sim.compute_hash()
    let key = "secret"
    let text = "HelloWorld"
    let cipher_sim = CipherSimulator(key: key, text: text)
    let encrypted_text = cipher_sim.encrypt()
    print("Computed Hash: \(computed_hash)")
    print("Encrypted Text: \(encrypted_text)")
}

main()