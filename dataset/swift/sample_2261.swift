func trackSequence(_ sequence: [Double]) -> Bool {
    let precision = 1e-10
    var lastValue = sequence[0]
    for value in sequence.dropFirst() {
        if abs(value - lastValue) < precision {
            return true
        }
        lastValue = value
    }
    return false
}

func main() {
    var sequence = [0.1, 0.2, 0.3, 0.4, 0.5]
    while true {
        if trackSequence(sequence) {
            break
        }
        sequence.append(sequence.last! + 0.1)
    }
}

main()