import Foundation

func hashSimulator() -> AnyIterator<String> {
    var iterator = AnyIterator {
        let data = String.random(in: 0...UInt128.max)
        let hashObject = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
        let hashDigest = hashObject.map { String(format: "%02hhx", $0) }.joined()
        return hashDigest
    }
    return iterator
}

func cipherSimulator() -> AnyIterator<String> {
    var iterator = AnyIterator {
        guard let hashDigest = hashSimulator().next() else { return nil }
        let key = String.random(in: 0...UInt256.max)
        let cipherText = zip(hashDigest, key).map {
            String(UnicodeScalar(((Character($0).asciiValue! + Character($1).asciiValue!) % 256)) ?? " ")
        }.joined()
        return cipherText
    }
    return iterator
}

func main() {
    for cipherText in cipherSimulator() {
        print(cipherText)
    }
}

main()