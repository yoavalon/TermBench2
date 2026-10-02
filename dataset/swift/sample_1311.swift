import Foundation

func hash_data(_ data: Data) -> String {
    let sha256 = Insecure.SHA256()
    let hashedData = sha256.hash(data)
    return hashedData.map { String(format: "%02hhx", $0) }.joined()
}

func simulate_cipher(_ data: String) -> String {
    var encrypted = ""
    for char in data {
        let shiftedChar = Character(UnicodeScalar((char.unicodeScalars.first!.value + 3) % 256)!)
        encrypted.append(shiftedChar)
    }
    return encrypted
}

func main() {
    let data = "Sample data for hashing and cipher simulation".data(using: .utf8)!
    let hashed = hash_data(data)
    let encrypted = simulate_cipher(hashed)
    print(encrypted)
}

main()