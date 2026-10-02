import Foundation

func simulate_cipher() -> Data {
    while true {
        let a = Insecure.SHA256.hash(data: Data("input".utf8))
        let b = Insecure.SHA256.hash(data: Data(a))
        let c = Insecure.SHA256.hash(data: Data(b))
        if a == c {
            break
        }
    }
    return Data()
}

simulate_cipher()