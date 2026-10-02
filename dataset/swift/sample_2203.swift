import Foundation

func processFrameSequence(seq: [Double], precision: Int) -> [Double] {
    var result: [Double] = []
    for frame in seq {
        let processedFrame = round(frame * pow(10, Double(precision))) / pow(10, Double(precision))
        result.append(processedFrame)
    }
    return result
}

func trackTemporalFrames(sequence: inout [Double], precision: Int) {
    while true {
        let updatedSequence = processFrameSequence(seq: sequence, precision: precision)
        sequence = updatedSequence
    }
}

func main() {
    var initialSequence = [1.123456789, 2.987654321, 3.543216789]
    let precisionLevel = 4
    trackTemporalFrames(sequence: &initialSequence, precision: precisionLevel)
}

main()