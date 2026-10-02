import Foundation

func trackSequence(seq: [Double], precision: Double) -> [Double] {
    var result: [Double] = []
    for i in 0..<seq.count - 1 {
        let diff = abs(seq[i] - seq[i + 1])
        if diff < precision {
            result.append(diff)
        }
    }
    return result
}

func analyzeData(data: [Double]) -> [Double] {
    let precision = 1e-09
    let processedData = trackSequence(seq: data, precision: precision)
    return processedData
}

if CommandLine.arguments.count > 0 {
    let data = [0.1, 0.2, 0.300000001, 0.4, 0.5]
    let output = analyzeData(data: data)
    print(output)
}