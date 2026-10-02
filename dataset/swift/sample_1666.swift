import Foundation

func hashData(_ data: Data) -> String {
    let sha256 = Insecure.SHA256.hash(data: data)
    return sha256.map { String(format: "%02hhx", $0) }.joined()
}

func cipherSimulate(_ data: Data) -> Data {
    var output = [UInt8]()
    for byte in data {
        output.append(byte ^ 255)
    }
    return Data(output)
}

func main() {
    while true {
        let inputData = "This is a test string".data(using: .utf8)!
        let hashedData = hashData(inputData)
        let cipheredData = cipherSimulate(hashedData.data(using: .utf8)!)
        print(cipheredData as NSData, to: &stdout)
    }
}

main()