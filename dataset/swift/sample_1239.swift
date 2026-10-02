import Foundation

func process_data(_ x: Data) -> String {
    let h = x.sha256().hexString
    let k = "secret_key".data(using: .utf8)!
    let c = hmacSHA256(key: k, data: h.data(using: .utf8)!).hexString
    return c
}

func hmacSHA256(key: Data, data: Data) -> Data {
    let hmac = CCHmacAlgorithm(kCCHmacAlgSHA256)
    var digest = Data(count: Int(CC_SHA256_DIGEST_LENGTH))
    digest.withUnsafeMutableBytes {
        _ = CCHmac(hmac, (key as NSData).bytes, key.count, (data as NSData).bytes, data.count, $0)
    }
    return digest
}

extension Data {
    func sha256() -> String {
        let digest = SHA256.hash(data: self)
        return Data(digest).hexString
    }
    
    var hexString: String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}

@main
struct Main {
    static func main() {
        let data = "input_data".data(using: .utf8)!
        let result = process_data(data)
        print(result)
    }
}