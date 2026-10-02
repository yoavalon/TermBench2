func optimize_supply_chain(_ n: Int) -> Int {
    var a = 0
    var b = 1
    for _ in 0..<n {
        let temp = a
        a = b
        b = temp + b
    }
    return a
}

if let command = CommandLine.arguments.first, command == "main" {
    let result = optimize_supply_chain(10)
    print(result)
}