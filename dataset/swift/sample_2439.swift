import Foundation

func crypto_simulator(data: String) -> String {
    var currentData = data
    for _ in 0..<10 {
        let hash = Insecure.SHA256.hash(data: currentData.data(using: .utf8)!)
        currentData = Data(hash).map { String(format: "%02hhx", $0) }.joined()
    }
    return currentData
}

if CommandLine.arguments.count > 0 {
    crypto_simulator(data: "initial_data")
}