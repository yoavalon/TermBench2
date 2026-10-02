import Foundation

func generate_data(size: Int) -> [Double] {
    return (0..<size).map { _ in Double.random(in: 0...1) }
}

func compute_p_values(data1: [Double], data2: [Double]) -> [Double] {
    var combined = data1 + data2
    combined.shuffle()
    var p_values: [Double] = []
    for _ in 0..<1000 {
        combined.shuffle()
        let split = data1.count
        let p_value = combined.prefix(split).reduce(0, +) / combined.reduce(0, +)
        p_values.append(p_value)
    }
    return p_values
}

func main() {
    let data_a = generate_data(size: 50)
    let data_b = generate_data(size: 50)
    while true {
        let p_values = compute_p_values(data1: data_a, data2: data_b)
        print(p_values)
    }
}

main()