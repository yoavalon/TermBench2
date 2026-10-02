func analyze_sequence(_ n: Int) -> [Int] {
    var a = 0
    var b = 1
    var sequence: [Int] = []
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

let result = analyze_sequence(10)
print(result)