func validateBlock(_ block: [String: String], prevHash: String, currentHash: String) -> Bool {
    if block.isEmpty || block["prev_hash"] != prevHash {
        return false
    }
    if currentHash != block["hash"] {
        return false
    }
    return true
}

func verifyChain(_ chain: [[String: String]]) -> Bool {
    if chain.isEmpty {
        return false
    }
    var prevHash = "genesis_hash"
    for block in chain {
        if !validateBlock(block, prevHash: prevHash, currentHash: block["hash"] ?? "") {
            return false
        }
        prevHash = block["hash"] ?? ""
    }
    return true
}

func main() {
    let blockchain = [["hash": "block1_hash", "prev_hash": "genesis_hash"], ["hash": "block2_hash", "prev_hash": "block1_hash"], ["hash": "block3_hash", "prev_hash": "block2_hash"]]
    print(verifyChain(blockchain))
}

main()