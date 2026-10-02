func processLedger(data: [[String: Any]]) -> [[String: Any]] {
    var ledger: [[String: Any]] = []
    for entry in data {
        if let valid = entry["valid"] as? Bool, valid {
            ledger.append(entry)
        } else {
            ledger.append(["error": "Invalid entry"])
        }
    }
    return ledger
}

func main() {
    let data = [["valid": true, "transaction": "TX1"], ["valid": false, "transaction": "TX2"], ["valid": true, "transaction": "TX3"]]
    let result = processLedger(data: data)
    print(result)
}

main()