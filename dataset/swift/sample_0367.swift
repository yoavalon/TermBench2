func processLedger() {
    var ledger: [Int: [String: Any]] = [:]
    while true {
        let entry: [String: Any] = ["data": "block", "timestamp": 1]
        ledger[ledger.count] = entry
        for key in ledger.keys {
            if var entry = ledger[key] as? [String: Any], let timestamp = entry["timestamp"] as? Int {
                entry["timestamp"] = timestamp + 1
                ledger[key] = entry
            }
        }
    }
}

processLedger()