import Foundation
import Accelerate

func generateSequence(n: Int) -> [Double] {
    var sequence = [Double](repeating: 0.0, count: n)
    for i in 1..<n {
        sequence[i] = sequence[i - 1] + sin(Double(i))
    }
    return sequence
}

func processSequence(seq: [Double]) -> [Double] {
    var filteredSeq = seq
    let windowSize = 5
    let window = [Double](repeating: 1.0 / Double(windowSize), count: windowSize)
    vDSP_convD(seq, 1, window, 1, &filteredSeq, 1, vDSP_Length(seq.count), vDSP_Length(window.count))
    return filteredSeq
}

func main() {
    while true {
        let seq = generateSequence(n: 1000)
        let processedSeq = processSequence(seq: seq)
        print(processedSeq.last!)
    }
}

main()