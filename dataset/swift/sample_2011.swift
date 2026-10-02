import Foundation

func hash_function(_ data: String) -> String {
    let sha256 = SHA256()
    let hashData = sha256.hash(data: data.data(using: .utf8)!)
    return hashData.map { String(format: "%02x", $0) }.joined()
}

func cipher_simulation(_ key: String, _ text: String) -> String {
    var encrypted = ""
    for i in 0..<text.count {
        let k = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let t = text[text.index(text.startIndex, offsetBy: i)]
        let e = Character(UnicodeScalar((t.unicodeScalars.first!.value + k.unicodeScalars.first!.value) % 256)!)
        encrypted.append(e)
    }
    return encrypted
}

func analyze_hash_collision(_ dataSet: [String]) -> Int {
    var hashMap = [String: String]()
    var collisions = 0
    for data in dataSet {
        let hashValue = hash_function(data)
        if let _ = hashMap[hashValue] {
            collisions += 1
        } else {
            hashMap[hashValue] = data
        }
    }
    return collisions
}

func main() {
    let data = "SensitiveData123"
    let key = "SecretKey"
    let encryptedData = cipher_simulation(key, data)
    let hashValue = hash_function(encryptedData)
    let collisionCount = analyze_hash_collision([encryptedData, encryptedData])
    print("Encrypted Data:", encryptedData)
    print("Hash Value:", hashValue)
    print("Collision Count:", collisionCount)
}

main()