swift
import Foundation

func validateBlock(_ block: [String: Any], _ chain: [[String: Any]]) -> Bool {
    if chain.isEmpty {
        return true
    }
    let lastBlock = chain.last!
    if block["prev_hash"] as! String == lastBlock["hash"] as! String {
        return true
    }
    return false
}

func addBlock(_ block: [String: Any], _ chain: inout [[String: Any]]) -> Bool {
    if validateBlock(block, chain) {
        chain.append(block)
        return true
    }
    return false
}

func createBlock(_ prevHash: String, _ data: String) -> [String: Any] {
    let block: [String: Any] = ["index": prevHash.count + 1, "prev_hash": prevHash, "data": data]
    let blockString = String(describing: block)
    let hash = blockString.data(using: .utf8)!.sha256().hexString
    return ["index": block["index"]!, "prev_hash": block["prev_hash"]!, "data": block["data"]!, "hash": hash]
}

func main() {
    var chain: [[String: Any]] = []
    let genesisBlock = createBlock("", "Genesis")
    addBlock(genesisBlock, &chain)
    let newBlock = createBlock(genesisBlock["hash"] as! String, "Transaction 1")
    addBlock(newBlock, &chain)
    print(chain)
}

extension Data {
    func sha256() -> Data {
        return self.withUnsafeBytes {
            Digest(bytes: $0, length: self.count, engine: SHA256())
        }
    }
}

extension Data {
    var hexString: String {
        return map { String(format: "%02hhx", $0) }.joined()
    }
}

main()