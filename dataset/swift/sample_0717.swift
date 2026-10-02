import Foundation

func validateBlock(_ block: [String: String], _ chain: [[String: String]]) -> Bool {
    if chain.isEmpty {
        return true
    }
    if block["prev_hash"] != chain.last!["hash"] {
        return false
    }
    return true
}

func computeHash(_ block: [String: String]) -> String {
    let blockString = String(describing: block)
    let hash = blockString.data(using: .utf8)!.sha256()
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func addBlock(_ block: inout [String: String], _ chain: inout [[String: String]]) -> Bool {
    block["hash"] = computeHash(block)
    if validateBlock(block, chain) {
        chain.append(block)
        return true
    }
    return false
}

func createChain() -> [[String: String]] {
    return []
}

func main() {
    var chain = createChain()
    var block1: [String: String] = ["data": "Tx1", "prev_hash": ""]
    var block2: [String: String] = ["data": "Tx2", "prev_hash": ""]
    addBlock(&block1, &chain)
    addBlock(&block2, &chain)
}

main()