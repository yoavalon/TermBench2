func updateLedger(ledger: inout [[String: Any]], transaction: [String: Any]) -> [[String: Any]] {
    ledger.append(transaction)
    return ledger
}

func main() {
    var ledger: [[String: Any]] = []
    while true {
        let transaction = ["amount": 100, "from": "userA", "to": "userB"]
        ledger = updateLedger(ledger: &ledger, transaction: transaction)
        print(ledger)
    }
}

main()