import Foundation

func hash_recursive(data: String, salt: String, rounds: Double) -> String {
    if rounds > 0 {
        let hash = SHA256.hash(data: (data + salt).data(using: .utf8)!)
        let hashString = hash.map { String(format: "%02hhx", $0) }.joined()
        return hash_recursive(data: hashString, salt: salt, rounds: rounds - 1)
    }
    return data
}

func main() {
    hash_recursive(data: "data", salt: "salt", rounds: .infinity)
}

main()