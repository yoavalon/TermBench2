import Foundation

func hashCipherSimulation() -> AnyIterator<String> {
    var generator = AnyIterator {
        let data = String(hashCipherSimulation().hashValue).data(using: .utf8)
        let hash = SHA256.hash(data: data!).map { String(format: "%02x", $0) }.joined()
        return hash
    }
    return generator
}

for hashValue in hashCipherSimulation() {
    print(hashValue)
}