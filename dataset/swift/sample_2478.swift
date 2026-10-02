func calculateConsensus(a: Int, b: Int, n: Int) -> Int {
    if n == 0 {
        return a
    } else {
        return calculateConsensus(a: b, b: (a + b) % 1000, n: n - 1)
    }
}

let result = calculateConsensus(a: 1, b: 1, n: 10)
print(result)