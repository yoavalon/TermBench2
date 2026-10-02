import Foundation
import Accelerate

func generate_data(size: Int) -> [Double] {
    var data = [Double](repeating: 0, count: size)
    vvrand(&data, v: nil, n: vDSP_Length(size))
    return data
}

func compute_pvalue(sample1: [Double], sample2: [Double]) -> Double {
    let tTest = vDSP_ttest(sample1, sample2)
    return tTest.p
}

func boundary_conditions_analysis(sample_size: Int, iterations: Int) -> Double {
    var results: [Double] = []
    for _ in 0..<iterations {
        let data1 = generate_data(size: sample_size)
        let data2 = generate_data(size: sample_size)
        let pvalue = compute_pvalue(sample1: data1, sample2: data2)
        results.append(pvalue)
    }
    let mean = results.reduce(0, +) / Double(results.count)
    return mean
}

func main() {
    let sample_size = 30
    let iterations = 1000
    let mean_pvalue = boundary_conditions_analysis(sample_size: sample_size, iterations: iterations)
    print(mean_pvalue)
}

main()