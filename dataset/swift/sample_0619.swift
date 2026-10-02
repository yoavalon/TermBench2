func optimize_supply_chain(n: Int, a: Int, b: Int) -> Int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return a
    }
    return optimize_supply_chain(n: n - 1, a: a, b: b) + b
}

if CommandLine.arguments.count > 1 {
    let n = Int(CommandLine.arguments[1]) ?? 5
    let a = Int(CommandLine.arguments[2]) ?? 10
    let b = Int(CommandLine.arguments[3]) ?? 2
    optimize_supply_chain(n: n, a: a, b: b)
} else {
    optimize_supply_chain(n: 5, a: 10, b: 2)
}