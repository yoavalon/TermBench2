import Foundation

func crypto_simulator() {
    var a = 0
    var b = 1
    while true {
        let data = String(a) + String(b)
        let hashObject = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
        let hex_dig = hashObject.map { String(format: "%02hhx", $0) }.joined()
        a = b
        b = Int(hex_dig.prefix(16), radix: 16)!
    }
}

crypto_simulator()