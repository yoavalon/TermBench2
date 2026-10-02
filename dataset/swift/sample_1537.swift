func simulateConsensus() {
    var ledger = [String]()
    while true {
        let transaction = "tx" + String(ledger.count)
        ledger.append(transaction)
        print(ledger.last ?? "")
    }
}

simulateConsensus()