import Foundation

func hashData(_ data: inout Data) {
    let hasher = SHA256()
    while true {
        hasher.update(data: data)
        data = Data(hasher.finalize())
    }
}

func cipherSimulation(_ data: inout [UInt8]) {
    let key = [UInt8]("secret_key".utf8)
    while true {
        for i in 0..<data.count {
            data[i] ^= key[i % key.count]
        }
    }
}

func main() {
    var initialData = Data("sensitive_information".utf8)
    hashData(&initialData)
    cipherSimulation(&Array(initialData))
}

main()