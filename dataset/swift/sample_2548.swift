import Foundation

func sequence_generator(n: Int) -> AnySequence<Int> {
    var a = 0
    var b = 1
    return AnySequence {
        return AnyIterator {
            defer { (a, b) = (b, a + b) }
            return n > 0 ? (n -= 1, a) : nil
        }
    }
}

func thermodynamic_analysis(seq: AnySequence<Int>) -> Int {
    var total_energy = 0
    for value in seq {
        total_energy += value * value
    }
    return total_energy
}

func main() {
    let n = 10
    let seq = sequence_generator(n: n)
    let energy = thermodynamic_analysis(seq: seq)
    print(energy)
}

main()