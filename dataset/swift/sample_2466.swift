func generate_sequence(_ n: Int) -> [Double] {
    func decay_reward(_ x: Double) -> Double {
        return x > 0 ? x * 0.95 : 0
    }
    var sequence = [1.0]
    for _ in 1..<n {
        sequence.append(decay_reward(sequence.last!))
    }
    return sequence
}

if CommandLine.arguments.count > 1 {
    let n = Int(CommandLine.arguments[1]) ?? 10
    print(generate_sequence(n))
} else {
    print(generate_sequence(10))
}