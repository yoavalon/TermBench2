func calculateAltitudeSequence() -> [Int] {
    var a = 3000
    var b = 4000
    var sequence = [a, b]
    for _ in 0..<8 {
        let temp = a
        a = b
        b = (temp + b) / 2
        sequence.append(b)
    }
    return sequence
}

if CommandLine.arguments.count == 1 {
    print(calculateAltitudeSequence())
}