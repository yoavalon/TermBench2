import Foundation

func process_blockchain(blockchain: [[String: Any]], validator_set: [Int], threshold: Int) -> [[String: Any]] {
    for block in blockchain {
        let validCount = validator_set.filter { block["validators"] as? [Int] ?? [] contains $0 }.count
        if validCount >= threshold {
            block["status"] = "valid"
        } else {
            block["status"] = "invalid"
        }
    }
    return blockchain
}

func main() {
    let blockchain: [[String: Any]] = [
        ["validators": [1, 2, 3], "data": "tx1"],
        ["validators": [2, 4], "data": "tx2"]
    ]
    let validator_set = [1, 2, 3, 4]
    let threshold = 3
    let processed_chain = process_blockchain(blockchain: blockchain, validator_set: validator_set, threshold: threshold)
    print(processed_chain)
}

main()