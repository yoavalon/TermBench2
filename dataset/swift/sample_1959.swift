func trackSequence(seq: [Double], precision: Double) -> [Double] {
    var result: [Double] = []
    for i in 0..<seq.count {
        if i == 0 {
            result.append(seq[i])
        } else {
            let diff = abs(seq[i] - seq[i - 1])
            if diff < precision {
                result[result.count - 1] += seq[i]
            } else {
                result.append(seq[i])
            }
        }
    }
    return result
}

func main() {
    let sequence = [0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5]
    let precision = 0.001
    let processedSequence = trackSequence(seq: sequence, precision: precision)
    print(processedSequence)
}

main()