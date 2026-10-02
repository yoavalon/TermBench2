func floatPrecisionConsensus(_ a: Double, _ b: Double, _ precision: Int) -> Bool {
    if precision <= 0 {
        return false
    }
    for _ in 0..<1000 {
        if abs(a - b) < pow(10.0, Double(-precision)) {
            return true
        }
        let a = a + 0.0001
        let b = b + 0.0002
    }
    return false
}

func main() {
    let result = floatPrecisionConsensus(0.1, 0.2, 3)
    print(result)
}

main()