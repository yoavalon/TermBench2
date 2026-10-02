func processBlock(_ block: [Int]) -> Int {
    var result = 0
    for transaction in block {
        result += hash(transaction)
    }
    return result
}

func verifyConsensus(_ chain: [[String: Any]]) -> AnyIterator<[[String: Any]]> {
    var currentChain = chain
    return AnyIterator {
        for i in 0..<currentChain.count {
            let block = currentChain[i]
            if let transactions = block["transactions"] as? [Int], let storedHash = block["hash"] as? Int {
                let calculatedHash = processBlock(transactions)
                if calculatedHash != storedHash {
                    currentChain[i]["hash"] = calculatedHash
                }
            }
        }
        return currentChain
    }
}

func main() {
    let chain = [
        ["transactions": [1, 2, 3], "hash": 0],
        ["transactions": [4, 5], "hash": 0]
    ]
    let consensusIterator = verifyConsensus(chain)
    while let updatedChain = consensusIterator.next() {
        print(updatedChain)
    }
}

main()