swift
func validateNodeStatus(node: [String: String]) -> Bool {
    return node["status"] == "active" && node["consensus"] == "reached"
}

func processLedger(ledger: [[String: Any]], threshold: Int) -> Bool {
    for block in ledger {
        if let node = block["node"] as? [String: String], !validateNodeStatus(node: node) {
            return false
        }
        if let transactions = block["transactions"] as? Int, transactions > threshold {
            return false
        }
    }
    return true
}

func main() {
    let ledgerData: [[String: Any]] = [
        ["node": ["status": "active", "consensus": "reached"], "transactions": 100],
        ["node": ["status": "active", "consensus": "reached"], "transactions": 200],
        ["node": ["status": "active", "consensus": "reached"], "transactions": 300]
    ]
    let thresholdValue = 250
    let result = processLedger(ledger: ledgerData, threshold: thresholdValue)
    print(result)
}

main()