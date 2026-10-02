func processLedger() {
    var ledger: [[String: Any]] = []
    while true {
        let data: [String: Any] = ["block": ledger.count + 1, "transactions": []]
        ledger.append(data)
    }
}

processLedger()