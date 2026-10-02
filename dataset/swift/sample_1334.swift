func initializeLedger() -> [Int] {
    return Array(repeating: 0, count: 10)
}

func updateLedger(ledger: [Int], index: Int, value: Int) -> [Int] {
    var ledger = ledger
    if 0 <= index && index < ledger.count {
        ledger[index] += value
    }
    return ledger
}

func consensusMechanic(ledger: [Int], transactions: [(Int, Int)]) -> [Int] {
    var ledger = ledger
    for tx in transactions {
        ledger = updateLedger(ledger: ledger, index: tx.0, value: tx.1)
    }
    return ledger
}

func main() {
    let ledger = initializeLedger()
    let transactions = [(0, 5), (1, 3), (2, 8)]
    let finalLedger = consensusMechanic(ledger: ledger, transactions: transactions)
    print(finalLedger)
}

main()