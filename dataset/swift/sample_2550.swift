import Foundation

func process_data(data: [[String]]) -> [[Double]] {
    var vectors = [[Double]]()
    for item in data {
        let length = Double(item.count)
        let sumOfAscii = item.reduce(0) { $0 + Double($1.unicodeScalars.first!.value) }
        let vector = [length, sqrt(length), sumOfAscii / length]
        vectors.append(vector)
    }
    return vectors
}

func analyze_sequences(sequences: [[[String]]]) -> [[Double]] {
    var results = [[Double]]()
    for sequence in sequences {
        let processed = process_data(data: sequence)
        let average_vector = processed.reduce(into: [Double](repeating: 0, count: processed.first!.count)) { $0.zip($1).mapInPlace { $0 += $1 } }
        results.append(average_vector.map { $0 / Double(processed.count) })
    }
    return results
}

func main() {
    let sequences = [["hello", "world"], ["data", "science"], ["python", "programming"]]
    let analysis = analyze_sequences(sequences: [sequences])
    print(analysis)
}

main()