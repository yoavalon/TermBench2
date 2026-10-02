import Foundation

func track_sequence(sequence: [Double], precision: Double) -> [Int] {
    var result = [Int]()
    for i in 0..<sequence.count - 1 {
        let diff = abs(sequence[i] - sequence[i + 1])
        if diff < precision {
            result.append(1)
        } else {
            result.append(0)
        }
    }
    return result
}

func analyze_sequence(sequence: [Double], precision: Double) -> Double {
    let tracked = track_sequence(sequence: sequence, precision: precision)
    let stability = Double(tracked.reduce(0, +)) / Double(tracked.count)
    return stability
}

func main() {
    let sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    let precision = 0.05
    let stability = analyze_sequence(sequence: sequence, precision: precision)
    print(stability)
}

main()