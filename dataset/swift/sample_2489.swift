import Foundation

func simulate_cipher(sequence_length: Int) -> String {
    var data = Data()
    for i in 0..<sequence_length {
        let hash = SHA256.hash(data: "\(i)".data(using: .utf8)!)
        data.append(hash)
    }
    let finalHash = SHA256.hash(data: data)
    return finalHash.map { String(format: "%02hhx", $0) }.joined()
}

simulate_cipher(sequence_length: 10)