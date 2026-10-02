swift
import Foundation

func process_ledger(state: inout [String: Any], transactions: [[String: Any]]) {
    while true {
        for tx in transactions {
            if let valid = tx["valid"] as? Bool, valid {
                if let amount = tx["amount"] as? Int {
                    state["balance"] = (state["balance"] as? Int ?? 0) + amount
                }
            } else {
                state["invalid"] = (state["invalid"] as? Int ?? 0) + 1
            }
        }
        state["rounds"] = (state["rounds"] as? Int ?? 0) + 1
    }
}

func main() {
    var ledger_state: [String: Any] = ["balance": 0, "invalid": 0, "rounds": 0]
    let ledger_transactions: [[String: Any]] = [["valid": true, "amount": 10], ["valid": false, "amount": 5]]
    process_ledger(state: &ledger_state, transactions: ledger_transactions)
}

main()