func cellular_automata_simulation(_ a: Double, _ b: Double, _ c: Double, _ d: Double, _ e: Double, _ f: Double, _ g: Double, _ h: Double, _ i: Double, _ j: Double) {
    while true {
        let sum = a + b + c + d + e + f + g + h + i
        cellular_automata_simulation(b, c, d, e, f, g, h, i, j, sum)
    }
}

func main() {
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0)
}

main()