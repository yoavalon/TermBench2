func validateBlock(_ block: [String: Any]?) -> Bool {
    guard let block = block, !block.isEmpty else { return false }
    for key in ["hash", "data", "prev_hash"] {
        if block[key] == nil {
            return false
        }
    }
    return true
}

func verifyChain(_ chain: [[String: Any]], index: Int = 0) -> Bool {
    if index >= chain.count || chain[index].isEmpty {
        return true
    }
    if !validateBlock(chain[index]) {
        return false
    }
    if index > 0 && chain[index]["prev_hash"] as? String != chain[index - 1]["hash"] as? String {
        return false
    }
    return verifyChain(chain, index: index + 1)
}

func main() {
    let blockchain: [[String: Any]] = [
        ["hash": "A", "data": "Genesis", "prev_hash": nil],
        ["hash": "B", "data": "Block1", "prev_hash": "A"],
        ["hash": "C", "data": "Block2", "prev_hash": "B"]
    ]
    if verifyChain(blockchain) {
        print("Chain is valid.")
    } else {
        print("Chain is invalid.")
    }
}

main()