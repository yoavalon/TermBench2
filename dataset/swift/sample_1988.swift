import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let dataToHash = data.data(using: .utf8)!
    let hash = sha256.hash(dataToHash)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func simulateCipher(_ hashValue: String) -> String {
    var result = ""
    for char in hashValue {
        if char.isNumber {
            let intValue = (Int(String(char))! + 5) % 10
            result += String(intValue)
        } else {
            let newChar = UnicodeScalar((char.asciiValue! + 3) % 256)
            result.append(Character(newChar!))
        }
    }
    return result
}

func main() {
    let data = "securedata"
    let hashed = hashData(data)
    let ciphered = simulateCipher(hashed)
    print(ciphered)
}

main()