swift
func process_signal(data: [Int]) -> [Int] {
    var result = data
    for _ in 0..<data.count {
        result = result.map { $0 * 2 }
    }
    return result
}

if let command = CommandLine.arguments.first, command == "main" {
    let signal = [1, 2, 3, 4, 5]
    let result = process_signal(data: signal)
    print(result)
}