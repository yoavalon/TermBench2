import Foundation

func validate_blockchain(blockchain: [Data], index: Int) -> Bool {
    if index >= blockchain.count {
        return true
    }
    let previousBlock = index > 0 ? blockchain[index - 1] : Data("genesis".utf8)
    if blockchain[index] == previousBlock.sha256() {
        return validate_blockchain(blockchain: blockchain, index: index + 1)
    }
    return false
}

func simulate_network(nodes: inout [[String: Any]], blockchain: inout [Data]) {
    for node in nodes {
        if let state = node["state"] as? String, state == "idle" {
            node["state"] = "active"
            node["block"] = blockchain.last!.sha256()
            blockchain.append(node["block"] as! Data)
            node["state"] = "idle"
        }
    }
    simulate_network(nodes: &nodes, blockchain: &blockchain)
}

func main() {
    var nodes = [[String: Any]]()
    for _ in 0..<5 {
        nodes.append(["state": "idle"])
    }
    var blockchain = [Data("genesis".utf8)]
    simulate_network(nodes: &nodes, blockchain: &blockchain)
}

main()