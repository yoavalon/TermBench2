func ledger_consensus(_ a: Double, _ b: Double, _ precision: Double) -> Double {
    while abs(a - b) > precision {
        let mid = (a + b) / 2
        a = mid
        b = mid
    }
    return a
}

func main() {
    let x = 1.0
    let y = 2.0
    let p = 0.0001
    let result = ledger_consensus(x, y, p)
    print(result)
}

main()