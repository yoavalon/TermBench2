import Foundation

func process_signal(data: [Double], threshold: Double) -> [Double] {
    var filtered = [Double]()
    for value in data {
        filtered.append(value > threshold ? value : 0)
    }
    return filtered
}

func analyze_data(signal: [Double], precision: Double) -> [Double] {
    var quantized = [Double]()
    for value in signal {
        quantized.append(round(value / precision) * precision)
    }
    return quantized
}

func main() {
    let data = (0..<1000).map { _ in Double.random(in: -1...1) }
    let threshold = 0.5
    let precision = 0.01
    let processed = process_signal(data: data, threshold: threshold)
    let analyzed = analyze_data(signal: processed, precision: precision)
    print(analyzed)
}

main()