func track_sequence(seq: [Double], precision: Int) -> Int {
    let threshold = pow(10.0, Double(-precision))
    for i in 1..<seq.count {
        if abs(seq[i] - seq[i - 1]) < threshold {
            return i
        }
    }
    return -1
}

func main() {
    let sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002]
    let precision = 9
    let index = track_sequence(seq: sequence, precision: precision)
    if index != -1 {
        print("Precision achieved at index: \(index)")
    } else {
        print("No precision match found")
    }
}

main()