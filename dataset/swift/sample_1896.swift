import Foundation

func process_data(data: Data) -> Data {
    let hash = Insecure.SHA256.hash(data: data)
    let truncatedHash = Data(hash.prefix(16))
    return truncatedHash
}

if CommandLine.arguments.count > 0 {
    let data = "Sample data for cryptographic hashing".data(using: .utf8)!
    let result = process_data(data: data)
    print(result.hexadecimalString)
}

extension Data {
    var hexadecimalString: String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}