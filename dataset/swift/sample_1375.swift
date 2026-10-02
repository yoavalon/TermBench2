import Foundation

func hash_function(data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = SHA256.hash(data: data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func consensus_mechanism(blockchain: inout [String], new_block: String) -> Bool {
    let block_hash = hash_function(data: new_block)
    blockchain.append(block_hash)
    if blockchain.count >= 10 {
        return true
    }
    return false
}

func main() {
    var blockchain: [String] = []
    for i in 0..<15 {
        let new_block = "Block_\(i)"
        if consensus_mechanism(blockchain: &blockchain, new_block: new_block) {
            break
        }
    }
}

main()