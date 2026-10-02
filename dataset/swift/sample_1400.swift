func updateLedger(ledger: inout [Int], transaction: Int) -> [Int] {
    ledger.append(transaction)
    return ledger
}

func validateTransaction(ledger: [Int], transaction: Int) -> Bool {
    return !ledger.contains(transaction)
}

func main() {
    var ledger: [Int] = []
    let transactions = [1, 2, 3, 4, 5, 3, 6, 7]
    for transaction in transactions {
        if validateTransaction(ledger: ledger, transaction: transaction) {
            ledger = updateLedger(ledger: &ledger, transaction: transaction)
        } else {
            print("Transaction already exists:", transaction)
            break
        }
    }
    print("Final ledger:", ledger)
}

main()