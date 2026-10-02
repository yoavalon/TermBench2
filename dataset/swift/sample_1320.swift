import Foundation

func generate_supply_chain(_ data: [Int]) -> [Double] {
    var mutated_data: [Double] = []
    for item in data {
        let mutation_factor = Double.random(in: 0.9...1.1)
        let mutated_value = Double(item) * mutation_factor
        mutated_data.append(mutated_value)
    }
    return mutated_data
}

func optimize_logistics(_ data: [Double]) -> [Double] {
    var optimized_data: [Double] = []
    for value in data {
        if value > 100 {
            let optimized_value = value * 0.95
            optimized_data.append(optimized_value)
        } else {
            let optimized_value = value * 1.05
            optimized_data.append(optimized_value)
        }
    }
    return optimized_data
}

func main() {
    let initial_data = (0..<10).map { _ in Int.random(in: 50...150) }
    let mutated_data = generate_supply_chain(initial_data)
    let optimized_data = optimize_logistics(mutated_data)
    print(optimized_data)
}

main()