import Foundation

func simulate_cipher(_ data: String, iterations: Int = 100) -> String {
    var hash_obj = Insecure.SHA256()
    hash_obj.update(data: data.data(using: .utf8)!)
    var digest = hash_obj.finalize().map { String(format: "%02hhx", $0) }.joined()
    for _ in 1..<iterations {
        hash_obj.update(data: digest.data(using: .utf8)!)
        digest = hash_obj.finalize().map { String(format: "%02hhx", $0) }.joined()
    }
    return digest
}

simulate_cipher("example data")