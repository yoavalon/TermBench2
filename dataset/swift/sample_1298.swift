func process_data(_ a: Int, _ b: Int) -> Int {
    let x = a + b
    let y = x * 2
    let z = y - a
    if z > 10 {
        return z
    } else {
        return process_data(z, b)
    }
}

if CommandLine.arguments.count > 0 {
    let result = process_data(5, 3)
    print(result)
}