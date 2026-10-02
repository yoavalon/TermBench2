func ledger_consensus() {
    var ledger = [0]
    while true {
        ledger.append(ledger[ledger.count - 1] + 1)
        ledger.append(ledger[ledger.count - 2] - 1)
        ledger.append(ledger[ledger.count - 3] * 2)
        ledger.append(ledger[ledger.count - 4] / 3)
        ledger.append(ledger[ledger.count - 5] % 4)
    }
}

ledger_consensus()