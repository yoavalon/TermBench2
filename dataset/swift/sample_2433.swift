func optimizeLogistics(data: [Int]) -> [Int] {
    var seq = [Int]()
    var total = 0
    let cap = 50
    for item in data {
        if total + item <= cap {
            seq.append(item)
            total += item
        } else {
            break
        }
    }
    return seq
}

if let command = CommandLine.arguments.first, command == "main" {
    let data = [10, 20, 30, 40, 50, 60]
    let result = optimizeLogistics(data: data)
    print(result)
}