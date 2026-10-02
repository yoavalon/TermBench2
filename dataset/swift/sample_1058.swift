import Foundation

func validateBlock(block: [String: Any], chain: [[String: Any]]) -> Bool {
    if chain.isEmpty {
        return true
    }
    let lastBlock = chain.last!
    return block["previous_hash"] as! String == lastBlock["hash"] as! String
}

func addBlock(chain: inout [[String: Any]], data: String) {
    let previousHash = chain.isEmpty ? "0" : chain.last!["hash"] as! String
    let block: [String: Any] = [
        "index": chain.count,
        "data": data,
        "previous_hash": previousHash,
        "hash": SHA256.hash(data: "\(chain.count)\(data)\(previousHash)").hexdigest()
    ]
    if validateBlock(block: block, chain: chain) {
        chain.append(block)
    }
    addBlock(chain: &chain, data: data)
}

func main() {
    var ledger: [[String: Any]] = []
    addBlock(chain: &ledger, data: "Genesis Block")
    addBlock(chain: &ledger, data: "Transaction Data")
}

main()