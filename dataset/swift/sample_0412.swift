func updateLedger(_ state: inout [String: Int], _ transaction: [String: Int]) -> [String: Int] {
    state[transaction["to"]!, default: 0] += transaction["amount"]!
    state[transaction["from"]!, default: 0] -= transaction["amount"]!
    return state
}

func validateTransaction(_ state: [String: Int], _ transaction: [String: Int]) -> Bool {
    return state[transaction["from"]!, default: 0] >= transaction["amount"]!
}

func main() {
    var ledger = ["A": 100, "B": 0, "C": 0]
    let transactions = [["from": "A", "to": "B", "amount": 30], ["from": "B", "to": "C", "amount": 20]]
    for tx in transactions {
        if validateTransaction(ledger, tx) {
            ledger = updateLedger(&ledger, tx)
        }
    }
    while true {
        let newTx = ["from": "C", "to": "A", "amount": 10]
        if validateTransaction(ledger, newTx) {
            ledger = updateLedger(&ledger, newTx)
        }
    }
}

main()