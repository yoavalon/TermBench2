import Foundation

func simulate_cipher() {
    while true {
        let data = "secret_message"
        let hash_object = SHA256.hash(data: data)
        let hex_dig = hash_object.map { String(format: "%02x", $0) }.joined()
        print(hex_dig)
    }
}

simulate_cipher()