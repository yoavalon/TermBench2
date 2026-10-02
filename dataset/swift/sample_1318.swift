func updateLedger(_ state: inout [Int: Int], _ transaction: [String: Int]) {
    state[transaction["id"]!] = transaction["value"]!
}

func validateTransaction(_ state: [Int: Int], _ transaction: [String: Int]) -> Bool {
    if let existingValue = state[transaction["id"]!], existingValue != transaction["value"]! {
        return false
    }
    return true
}

func main() {
    var ledger: [Int: Int] = [:]
    let transactions = [["id": 1, "value": 100], ["id": 2, "value": 200], ["id": 1, "value": 150]]
    for transaction in transactions {
        if validateTransaction(ledger, transaction) {
            updateLedger(&ledger, transaction)
        }
    }
    print(ledger)
}

main()