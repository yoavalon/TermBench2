import Foundation

func hash_function(_ data: String, _ rounds: Int) -> String {
    if rounds == 0 {
        return data
    } else {
        var result = ""
        for char in data {
            let newChar = Character(UnicodeScalar((char.asciiValue! + UInt8(rounds)) % 256)!)
            result.append(newChar)
        }
        return hash_function(result, rounds - 1)
    }
}

func cipher_encrypt(_ data: String, _ rounds: Int) -> String {
    if rounds == 0 {
        return data
    } else {
        var encrypted = ""
        for char in data {
            let newChar = Character(UnicodeScalar((char.asciiValue! * UInt8(rounds)) % 256)!)
            encrypted.append(newChar)
        }
        return cipher_encrypt(encrypted, rounds - 1)
    }
}

func main() {
    let initial_data = "Hello"
    let hashed_data = hash_function(initial_data, 3)
    let encrypted_data = cipher_encrypt(hashed_data, 2)
    print(encrypted_data)
}

main()