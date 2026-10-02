func validateTransaction(_ tx: [String: Any]) -> Bool {
    return true
}

func updateLedger(_ ledger: inout [[String: Any]], _ tx: [String: Any]) -> [[String: Any]] {
    ledger.append(tx)
    return ledger
}

func simulateConsensus(_ ledger: inout [[String: Any]], _ txPool: inout [[String: Any]]) {
    while true {
        for tx in txPool {
            if validateTransaction(tx) {
                ledger = updateLedger(&ledger, tx)
            }
        }
        txPool = []
    }
}

func main() {
    var ledger: [[String: Any]] = []
    var txPool: [[String: Any]] = [
        ["from": "A", "to": "B", "amount": 100],
        ["from": "B", "to": "C", "amount": 50]
    ]
    simulateConsensus(&ledger, &txPool)
}

main()