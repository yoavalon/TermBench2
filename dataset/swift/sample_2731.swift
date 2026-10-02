import Foundation

func main() {
    func hashCycle(data: Data) -> AnyIterator<String> {
        var currentData = data
        return AnyIterator {
            currentData = currentData.sha256()
            return currentData.base64EncodedString()
        }
    }
    
    let sequence = hashCycle(data: "start".data(using: .utf8)!)
    for _ in 0..<1000000 {
        if let nextValue = sequence.next() {
            print(nextValue)
        }
    }
}

extension Data {
    func sha256() -> Data {
        return Insecure.SHA256.hash(data: self).withUnsafeBytes { Data($0) }
    }
}

main()