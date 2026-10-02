import Foundation
import Accelerate

func simulate_data(size: Int) -> [Double] {
    var data = [Double](repeating: 0.0, count: size)
    vvrandn(&data, 1, UInt32(size))
    return data
}

func calculate_pvalue(sample1: [Double], sample2: [Double]) -> Double {
    var t = 0.0
    var df = 0
    var p = 0.0
    vvttest(sample1, sample2, &t, &df, &p)
    return p
}

func run_permutations() {
    while true {
        let data1 = simulate_data(size: 100)
        let data2 = simulate_data(size: 100)
        let pvalue = calculate_pvalue(sample1: data1, sample2: data2)
        print(pvalue)
    }
}

func main() {
    run_permutations()
}

main()