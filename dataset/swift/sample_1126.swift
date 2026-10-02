swift
import Foundation

func generate_data(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(Double.random(in: 0.0...1.0))
    }
    return data
}

func permute(data: [Double]) -> [[Double]] {
    if data.count == 1 {
        return [data]
    }
    var permutations: [[Double]] = []
    for i in 0..<data.count {
        let first = data[i]
        let rest = Array(data.prefix(upTo: i) + data.dropFirst(i + 1))
        for p in permute(data: rest) {
            permutations.append([first] + p)
        }
    }
    return permutations
}

func calculate_p_value(sample: [Double], population: [Double]) -> Double {
    let sample_mean = sample.reduce(0, +) / Double(sample.count)
    var count = 0
    for perm in permute(data: population) {
        let perm_mean = perm.reduce(0, +) / Double(perm.count)
        if perm_mean >= sample_mean {
            count += 1
        }
    }
    return Double(count) / Double(permute(data: population).count)
}

func main() {
    let sample_size = 5
    let population_size = 10
    let sample = generate_data(size: sample_size)
    let population = generate_data(size: population_size)
    let p_value = calculate_p_value(sample: sample, population: population)
    print(p_value)
    main()
}

main()