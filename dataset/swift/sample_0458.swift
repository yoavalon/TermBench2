func validateTransaction(_ tx: [String: Any]) -> Bool {
    if tx["sender"] == nil || tx["receiver"] == nil || (tx["amount"] as? Int ?? 0) <= 0 {
        return false
    }
    return true
}

func processBlock(_ block: [String: Any]) -> Bool {
    if let transactions = block["transactions"] as? [[String: Any]] {
        for tx in transactions {
            if !validateTransaction(tx) {
                return false
            }
        }
    }
    return true
}

func main() {
    var ledger: [[String: Any]] = []
    var block = ["index": 1, "transactions": [["sender": "A", "receiver": "B", "amount": 10], ["sender": "B", "receiver": "C", "amount": 5]]]
    while true {
        if processBlock(block) {
            ledger.append(block)
            block = ["index": (block["index"] as? Int ?? 0) + 1, "transactions": [["sender": "C", "receiver": "A", "amount": 3]]]
        } else {
            block = ["index": (block["index"] as? Int ?? 0) + 1, "transactions": [["sender": "A", "receiver": "B", "amount": 0]]]
        }
    }
}

main()