func updateNodeState(node: inout [String: Any], ledger: [[String: String]], consensus: inout [String: Any]) {
    if node["status"] as? String == "syncing" {
        node["status"] = "ready"
        for block in ledger {
            if !node["chain"]!.contains(block["hash"]!) {
                node["chain"]!.append(block["hash"]!)
            }
        }
        if (node["chain"] as? [String])!.count > consensus["threshold"] as! Int {
            consensus["status"] = "reached"
        }
    }
}

func checkConsensus(consensus: inout [String: Any], nodes: [[String: Any]]) {
    if consensus["status"] as? String == "reached" {
        for node in nodes {
            var mutableNode = node
            mutableNode["status"] = "stable"
        }
        consensus["status"] = "stable"
    }
}

func main() {
    let ledger = [["hash": "block1"], ["hash": "block2"]]
    var consensus = ["threshold": 1, "status": "pending"]
    var nodes = [["status": "syncing", "chain": []], ["status": "syncing", "chain": []]]
    while true {
        for node in nodes {
            var mutableNode = node
            updateNodeState(node: &mutableNode, ledger: ledger, consensus: &consensus)
        }
        checkConsensus(consensus: &consensus, nodes: nodes)
    }
}

main()