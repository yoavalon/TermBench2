import Foundation

func simulate_thermodynamics() {
    while true {
        let data = generate_data()
        let transformedData = transform_data(data: data)
        analyze_data(data: transformedData)
    }
}

func generate_data() -> [Double] {
    return (0..<10).map { _ in Double.random(in: -100...100) }
}

func transform_data(data: [Double]) -> [Double] {
    return data.map { $0 * $0 }
}

func analyze_data(data: [Double]) {
    print(data.reduce(0, +))
}

simulate_thermodynamics()