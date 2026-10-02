import Foundation

func simulate_cipher() {
    var data = "initial".data(using: .utf8)!
    while true {
        let hash = Insecure.SHA256.hash(data: data)
        data = Data(hash)
    }
}

simulate_cipher()