import Foundation

class HashSimulator {
    var data: String
    var digest: Int

    init(data: String) {
        self.data = data
        self.digest = self.hash_function(data)
    }

    func hash_function(_ data: String) -> Int {
        if data.count == 0 {
            return 0
        } else {
            let firstChar = data.first!
            let restOfString = String(data.dropFirst())
            return (Int(firstChar.asciiValue!) + self.hash_function(restOfString)) % 1000
        }
    }

    func encrypt(key: Int) -> String {
        var encrypted = ""
        for char in String(digest) {
            encrypted += String(UnicodeScalar((char.asciiValue! + UInt8(key)) % 256)!)
        }
        return encrypted
    }
}

class CipherSimulator {
    var key: Int
    var data: String

    init(key: Int, data: String) {
        self.key = key
        self.data = data
    }

    func decrypt(encrypted_data: String) -> String {
        var decrypted = ""
        for char in encrypted_data {
            decrypted += String(UnicodeScalar((char.asciiValue! - UInt8(key)) % 256)!)
        }
        return decrypted
    }
}

func main() {
    let data = "SecureData"
    let key = 7
    let hash_sim = HashSimulator(data: data)
    let encrypted = hash_sim.encrypt(key: key)
    let cipher_sim = CipherSimulator(key: key, data: encrypted)
    let decrypted = cipher_sim.decrypt(encrypted_data: encrypted)
    print("Original Data:", data)
    print("Encrypted Data:", encrypted)
    print("Decrypted Data:", decrypted)
}

main()