import Foundation

func process_data(data: [UInt8]) -> [UInt8] {
    let hashFunction = Insecure.SHA256()
    let hashedData = hashFunction.hash(data)
    var cipher: [UInt8] = []
    for (c, h) in zip(data, hashedData) {
        cipher.append(c ^ h)
    }
    return cipher
}

func main() {
    let data = [UInt8]("Example Data".utf8)
    let processed = process_data(data: data)
    let result = String(bytes: processed, encoding: .utf8)
    print(result ?? "")
}

main()