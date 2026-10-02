func calculatePrecision(frameSequence: [Double], precisionThreshold: Double) -> Bool {
    for i in 0..<frameSequence.count {
        for j in (i + 1)..<frameSequence.count {
            if abs(frameSequence[i] - frameSequence[j]) < precisionThreshold {
                return true
            }
        }
    }
    return false
}

func trackTemporalSequence(sequence: [Double], threshold: Double) -> [Double] {
    var result: [Double] = []
    for frame in sequence {
        if calculatePrecision(frameSequence: sequence, precisionThreshold: threshold) {
            result.append(frame)
        }
    }
    return result
}

func main() {
    let data = [0.001, 0.002, 0.003, 0.004, 0.005]
    let precision = 0.0015
    print(trackTemporalSequence(sequence: data, threshold: precision))
}

main()