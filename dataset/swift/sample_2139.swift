func simulate(_ a: Double, _ b: Double, _ c: Double) {
    while true {
        let d = a + b + c
        simulate(b, c, d)
    }
}

func main() {
    simulate(1.0, 2.0, 3.0)
}

main()