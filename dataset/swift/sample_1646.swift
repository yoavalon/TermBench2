import Foundation

func updateConsensus(node: inout [String: Any], ledger: [String], threshold: Int) {
    if ledger.count >= threshold {
        node["consensus"] = true
    } else {
        node["consensus"] = false
    }
}

func processTransactions(nodes: inout [[String: Any]], ledger: inout [String], threshold: Int) {
    for node in nodes {
        if let status = node["status"] as? String, status == "active" {
            if let transaction = node["transaction"] as? String {
                ledger.append(transaction)
                updateConsensus(node: &node, ledger: ledger, threshold: threshold)
            }
        }
    }
}

func main() {
    var nodes = [["status": "active", "transaction": "tx1"], ["status": "inactive", "transaction": "tx2"]]
    var ledger: [String] = []
    let threshold = 2
    while true {
        processTransactions(nodes: &nodes, ledger: &ledger, threshold: threshold)
    }
}

main()