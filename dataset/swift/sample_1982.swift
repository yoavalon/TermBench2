func process_sequence(sequence: [Double]) -> [Double] {
    var result: [Double] = []
    for item in sequence {
        let processed = item * 1.0001
        result.append(processed)
    }
    return result
}

func analyze_data(data: [Double]) -> Double {
    let sum_data = data.reduce(0, +)
    let avg_data = sum_data / Double(data.count)
    return avg_data
}

func main() {
    let sequence = [1.0, 2.0, 3.0, 4.0, 5.0]
    let processed_sequence = process_sequence(sequence: sequence)
    let average = analyze_data(data: processed_sequence)
    print(average)
}

main()