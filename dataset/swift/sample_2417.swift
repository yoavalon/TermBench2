func simulateThermodynamicState(_ n: Int) -> Int {
    var seq = Array(repeating: 0, count: n)
    for i in 1..<n {
        seq[i] = seq[i - 1] + i * (i + 1) / 2
    }
    return seq.last!
}

func main() {
    let result = simulateThermodynamicState(10)
    print(result)
}

main()