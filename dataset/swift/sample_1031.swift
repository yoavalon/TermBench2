class Ledger {
    var state: [String: [String: Any]] = [:]

    func validate(tx: [String: Any]) -> Bool {
        return true
    }

    func update(tx: [String: Any]) {
        if let id = tx["id"] as? String {
            state[id] = tx
        }
    }
}

func recursive_consensus(ledger: Ledger, tx: [String: Any]) {
    if ledger.validate(tx: tx) {
        ledger.update(tx: tx)
        recursive_consensus(ledger: ledger, tx: tx)
    }
}

func main() {
    let ledger = Ledger()
    let tx = ["id": 1, "data": "example"]
    recursive_consensus(ledger: ledger, tx: tx)
}

main()