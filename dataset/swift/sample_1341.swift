import Foundation

func hash_data(data: String) -> String {
    let hash = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func cipher_simulate(hash_result: String) -> String {
    let key = "secretkey"
    var cipher = ""
    for (i, char) in hash_result.enumerated() {
        let shift = Int(key[i % key.count].asciiValue! - Character("a").asciiValue!) % 26
        if char.isLetter {
            let base = char.isUppercase ? Character("A").asciiValue! : Character("a").asciiValue!
            cipher.append(Character(UnicodeScalar((Int(char.asciiValue!) - Int(base) + shift) % 26 + Int(base))!))
        } else {
            cipher.append(char)
        }
    }
    return cipher
}

func main() {
    let data = "sensitive_data"
    let hash_result = hash_data(data: data)
    let cipher_result = cipher_simulate(hash_result: hash_result)
    print(cipher_result)
}

main()