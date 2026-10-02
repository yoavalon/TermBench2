swift
func processSignal(data: [Int], threshold: Int) -> [Int] {
    var filtered = [Int]()
    for val in data {
        if val > threshold {
            filtered.append(val)
        }
    }
    return filtered
}

if let command = CommandLine.arguments.first, command == "main" {
    let signal = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    let threshold = 50
    let result = processSignal(data: signal, threshold: threshold)
    print(result)
}