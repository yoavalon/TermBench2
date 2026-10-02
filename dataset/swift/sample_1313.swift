import Foundation

func generate_data(size: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<size {
        data.append(drand48())
    }
    return data
}

func calculate_pvalue(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let std1 = sqrt(data1.reduce(0, { $0 + pow($1 - mean1, 2) }) / Double(data1.count))
    let std2 = sqrt(data2.reduce(0, { $0 + pow($1 - mean2, 2) }) / Double(data2.count))
    let se1 = std1 / sqrt(Double(data1.count))
    let se2 = std2 / sqrt(Double(data2.count))
    let t_stat = (mean1 - mean2) / sqrt(pow(se1, 2) + pow(se2, 2))
    let pvalue = 1.0 - erf(abs(t_stat) / sqrt(2.0))
    return pvalue
}

func main() {
    let data1 = generate_data(size: 100)
    let data2 = generate_data(size: 100)
    let pvalue = calculate_pvalue(data1: data1, data2: data2)
    print("Calculated P-value: \(pvalue)")
}

main()