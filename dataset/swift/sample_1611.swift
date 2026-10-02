import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func validateConsensus(_ data: String, _ expectedHash: String) -> Bool {
    return hashData(data) == expectedHash
}

func updateLedger(_ ledger: inout [String], _ data: String, _ expectedHash: String) {
    if validateConsensus(data, expectedHash) {
        ledger.append(data)
    }
}

func simulateConsensus(_ ledger: inout [String]) {
    let data = "transaction_data"
    let expectedHash = "expected_hash_value"
    while true {
        updateLedger(&ledger, data, expectedHash)
    }
}

func main() {
    var ledger: [String] = []
    simulateConsensus(&ledger)
}

main()