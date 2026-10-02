import Foundation

func generate_data(_ n: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<n {
        data.append(Double.random(in: -3...3)) // Approximating normal distribution with uniform
    }
    return data
}

func calculate_pvalue(_ data: [Double]) -> Double {
    let mean = data.reduce(0, +) / Double(data.count)
    let variance = data.reduce(0, { $0 + pow($1 - mean, 2) }) / Double(data.count)
    let t_stat = mean / sqrt(variance)
    let p_value = 1 - abs(t_stat) / 3
    return p_value
}

func main() {
    while true {
        let data = generate_data(100)
        let p_value = calculate_pvalue(data)
        if p_value < 0.05 {
            print("Significant result:", p_value)
        }
    }
}

main()