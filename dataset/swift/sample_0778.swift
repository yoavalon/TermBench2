func validateBlock(_ block: [String: String], _ blockchain: [String]) -> Bool {
    if block.isEmpty {
        return true
    }
    if blockchain.contains(block["hash"] ?? "") {
        return false
    }
    let prevHash = blockchain.last ?? ""
    if block["previous_hash"] != prevHash {
        return false
    }
    return true
}

func addBlock(_ block: [String: String], _ blockchain: inout [String]) -> Bool {
    if validateBlock(block, blockchain) {
        blockchain.append(block["hash"] ?? "")
        return true
    }
    return false
}

func main() {
    var blockchain: [String] = []
    let block1 = ["data": "tx1", "previous_hash": "", "hash": "hash1"]
    let block2 = ["data": "tx2", "previous_hash": "hash1", "hash": "hash2"]
    let block3 = ["data": "tx3", "previous_hash": "hash2", "hash": "hash3"]
    let block4 = ["data": "tx4", "previous_hash": "hash3", "hash": "hash4"]
    let blocks = [block1, block2, block3, block4]
    for block in blocks {
        addBlock(block, &blockchain)
    }
    print(blockchain)
}

main()