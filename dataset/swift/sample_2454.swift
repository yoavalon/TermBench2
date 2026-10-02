import Foundation

func process_sequence(data: [Any]) -> [Int] {
    var result: [Int] = []
    for i in 0..<data.count {
        let hashObject = Insecure.SHA256.hash(data: String(data[i]).data(using: .utf8)!)
        let hashString = hashObject.map { String(format: "%02hhx", $0) }.joined()
        let hashValue = Int(hashString, radix: 16) ?? 0
        result.append(hashValue % 1000)
    }
    return result
}

if let command = CommandLine.arguments.first, command == "main" {
    let data = [1, 2, 3, 4, 5]
    print(process_sequence(data: data))
}