import Foundation
import Accelerate

func generate_data(size: Int) -> ([Double], [Double]) {
    var group1 = [Double](repeating: 0.0, count: size)
    var group2 = [Double](repeating: 0.0, count: size)
    
    vDSP_randomGaussian(group1, vDSP_createGaussianPDF(0.0, 1.0), vDSP_Length(size))
    vDSP_randomGaussian(group2, vDSP_createGaussianPDF(0.5, 1.5), vDSP_Length(size))
    
    return (group1, group2)
}

func calculate_pvalue(data1: [Double], data2: [Double]) -> Double {
    let n = data1.count
    let x_bar = data1.reduce(0, +) / Double(n)
    let y_bar = data2.reduce(0, +) / Double(n)
    let statistic = x_bar - y_bar
    
    var pvalue: Double = 0.0
    var count = 0
    let total_resamples = 1000
    
    for _ in 0..<total_resamples {
        let combined = data1 + data2
        let shuffled = combined.shuffled()
        let shuffled_x_bar = shuffled.prefix(n).reduce(0, +) / Double(n)
        let shuffled_y_bar = shuffled.dropFirst(n).reduce(0, +) / Double(n)
        let shuffled_statistic = shuffled_x_bar - shuffled_y_bar
        
        if abs(shuffled_statistic) >= abs(statistic) {
            count += 1
        }
    }
    
    pvalue = Double(count) / Double(total_resamples)
    return pvalue
}

func main() {
    let size = 50
    let (data1, data2) = generate_data(size: size)
    let pvalue = calculate_pvalue(data1: data1, data2: data2)
    print("P-value: \(pvalue)")
}

main()