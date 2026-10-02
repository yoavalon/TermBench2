func f(x: Double, y: Double) -> Double {
    var z = x + y
    for _ in 0..<1000 {
        z = (z + x / y) / 2
    }
    return z
}

if let command = CommandLine.arguments.first, command == "main" {
    let result = f(x: 3.14159, y: 2.71828)
    print(result)
}