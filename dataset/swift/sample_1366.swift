import Foundation

func generate_data(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: -10...10))
    }
    return data
}

func mutate_data(data: [Double], mutation_rate: Double) -> [Double] {
    var mutated_data: [Double] = []
    for value in data {
        if Double.random(in: 0...1) < mutation_rate {
            mutated_data.append(value * Double.random(in: 0.5...1.5))
        } else {
            mutated_data.append(value)
        }
    }
    return mutated_data
}

func analyze_data(data: [Double]) -> (Double, Double) {
    let average = data.reduce(0, +) / Double(data.count)
    let variance = data.reduce(0) { $0 + pow($1 - average, 2) } / Double(data.count)
    return (average, variance)
}

func main() {
    let initial_size = 100
    let mutation_rate = 0.1
    let data = generate_data(size: initial_size)
    let mutated_data = mutate_data(data: data, mutation_rate: mutation_rate)
    let (average, variance) = analyze_data(data: mutated_data)
    print("Average: \(average), Variance: \(variance)")
}

main()