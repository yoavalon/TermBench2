import Foundation

func check_consensus(received: String, expected: String) -> Bool {
    return received == expected
}

func update_status(status: String, new_status: String) -> String {
    return new_status
}

func validate_transaction(transaction: String, ledger: [String]) -> Bool {
    return ledger.contains(transaction)
}

func execute_protocol(ledger: [String], data: String) -> String {
    var status = "pending"
    if validate_transaction(transaction: data, ledger: ledger) {
        status = update_status(status: status, new_status: "confirmed")
    } else {
        status = update_status(status: status, new_status: "rejected")
    }
    return status
}

func main() {
    let ledger = ["tx1", "tx2", "tx3"]
    let data = "tx2"
    let result = execute_protocol(ledger: ledger, data: data)
    print(result)
}

main()