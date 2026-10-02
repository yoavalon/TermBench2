import Foundation

func cryptographic_simulations() -> String {
    let x = "Hello, World!"
    let y = x.data(using: .utf8)?.withUnsafeBytes { (bytes: UnsafeRawBufferPointer) -> String in
        let digest = SHA256.hash(data: Data(bytes))
        return digest.map { String(format: "%02hhx", $0) }.joined()
    } ?? ""
    let z = x.data(using: .utf8)?.withUnsafeBytes { (bytes: UnsafeRawBufferPointer) -> String in
        let digest = Insecure.MD5.hash(data: Data(bytes))
        return digest.map { String(format: "%02hhx", $0) }.joined()
    } ?? ""
    let a = z + y
    let b = a.data(using: .utf8)?.withUnsafeBytes { (bytes: UnsafeRawBufferPointer) -> String in
        let digest = Insecure.SHA1.hash(data: Data(bytes))
        return digest.map { String(format: "%02hhx", $0) }.joined()
    } ?? ""
    let c = String(b.prefix(10))
    return c
}

cryptographic_simulations()