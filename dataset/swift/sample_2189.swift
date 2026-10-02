import Foundation

func simulate(a: Double, b: Double, c: Double) -> AnySequence<(Double, Double, Double)> {
    sequence(state: (a, b, c)) { state -> Optional<(Double, Double, Double)> in
        let (a, b, c) = state
        let newA = b
        let newB = c
        let newC = (a + b + c) / 3
        state = (newA, newB, newC)
        return (newA, newB, newC)
    }
}

func main() {
    for (x, y, z) in simulate(a: 1.0, b: 2.0, c: 3.0) {
        print(String(format: "%.5f, %.5f, %.5f", x, y, z))
    }
}

main()