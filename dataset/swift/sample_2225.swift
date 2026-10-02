import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
    return sha256.map { String(format: "%02hhx", $0) }.joined()
}

func simulateCipher(_ seed: String) -> String {
    let hashed = hashData(seed)
    var cipher = ""
    for char in hashed {
        if let digit = char.wholeNumberValue {
            cipher.append(Character(UnicodeScalar((digit + 1) % 10 + 48)!))
        } else {
            cipher.append(Character(UnicodeScalar((char.asciiValue! + 1) % 256)!))
        }
    }
    return cipher
}

func main() {
    var seed = "initial_seed"
    while true {
        seed = simulateCipher(seed)
        print(seed)
    }
}

main()