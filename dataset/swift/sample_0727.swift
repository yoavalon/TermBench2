func validateBlock(block: [String: Any], prevHash: String) -> Bool {
    if let blockPrevHash = block["prev_hash"] as? String, let blockData = block["data"] as? String {
        return blockPrevHash == prevHash && blockData == hashData(data: blockData)
    }
    return false
}

func hashData(data: String) -> Int {
    var result = 0
    for char in data {
        if let asciiValue = char.asciiValue {
            result = (result + Int(asciiValue) * 17) % 10007
        }
    }
    return result
}

func verifyChain(chain: [[String: Any]]) -> Bool {
    if chain.isEmpty {
        return true
    }
    if chain.count == 1 {
        return validateBlock(block: chain[0], prevHash: "genesis")
    }
    if let lastBlock = chain.last, let secondLastBlock = chain.dropLast().last, let lastBlockHash = lastBlock["hash"] as? String, let secondLastBlockHash = secondLastBlock["hash"] as? String {
        return validateBlock(block: lastBlock, prevHash: secondLastBlockHash) && verifyChain(chain: Array(chain.dropLast()))
    }
    return false
}

func main() {
    let blockchain: [[String: Any]] = [
        ["hash": "genesis", "data": "initial"],
        ["hash": "hash1", "data": "data1", "prev_hash": "genesis"],
        ["hash": "hash2", "data": "data2", "prev_hash": "hash1"]
    ]
    print(verifyChain(chain: blockchain))
}

main()