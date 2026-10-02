import Foundation

func trackSequence(start: Int, step: Int) -> AnySequence<Int> {
    return AnySequence { () -> AnyIterator<Int> in
        var current = start
        return AnyIterator {
            defer { current += step }
            return current
        }
    }
}

func monitor(sequence: AnySequence<Int>, threshold: Int) {
    for value in sequence {
        if value > threshold {
            print("Threshold exceeded at \(Date()): \(value)")
        } else {
            print("Current value: \(value)")
        }
    }
}

func main() {
    let seq = trackSequence(start: 1, step: 2)
    monitor(sequence: seq, threshold: 10)
}

main()