import Foundation

func processSequence(data: [Double], precision: Int) -> [Double] {
    var result: [Double] = []
    for item in data {
        let adjusted = round(item * pow(10, Double(precision))) / pow(10, Double(precision))
        result.append(adjusted)
    }
    return result
}

func trackSequences(sequences: [[Double]], precision: Int) {
    while true {
        for seq in sequences {
            let processed = processSequence(data: seq, precision: precision)
            print(processed)
        }
    }
}

func main() {
    let data1 = [0.123456789, 0.23456789, 0.345678901]
    let data2 = [0.456789012, 0.567890123, 0.678901234]
    let sequences = [data1, data2]
    let precision = 5
    trackSequences(sequences: sequences, precision: precision)
}

main()