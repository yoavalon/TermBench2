import Foundation

func hashSequence(_ data: [Any]) -> [String] {
    var result: [String] = []
    for item in data {
        let hashObject = Insecure.SHA256.hash(data: String(describing: item).data(using: .utf8)!)
        result.append(hashObject.map { String(format: "%02x", $0) }.joined())
    }
    return result
}

func cipherSequence(_ data: [String], _ key: Int) -> [String] {
    var result: [String] = []
    for item in data {
        let encryptedItem = item.map { String(UnicodeScalar((($0.asciiValue ?? 0) + UInt8(key)) % 256)) }.joined()
        result.append(encryptedItem)
    }
    return result
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let key = 5
    let hashedData = hashSequence(data)
    let cipheredData = cipherSequence(hashedData, key)
    print(cipheredData)
}

main()