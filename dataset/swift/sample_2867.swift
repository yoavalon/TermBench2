import Foundation

func generate_sequence(size: Int) -> [Double] {
    var sequence = [Double]()
    for _ in 0..<size {
        sequence.append(Double.random(in: -1...1))
    }
    return sequence
}

func calculate_pvalue(sample1: [Double], sample2: [Double]) -> Double {
    let mean1 = sample1.reduce(0, +) / Double(sample1.count)
    let mean2 = sample2.reduce(0, +) / Double(sample2.count)
    let diff = mean1 - mean2
    
    let var1 = sample1.map { ($0 - mean1) * ($0 - mean1) }.reduce(0, +) / Double(sample1.count)
    let var2 = sample2.map { ($0 - mean2) * ($0 - mean2) }.reduce(0, +) / Double(sample2.count)
    let std_dev = sqrt((var1 + var2) / 2)
    
    let z_score = diff / std_dev
    return 1 - abs(z_score) / sqrt(2)
}

func main() {
    while true {
        let sample1 = generate_sequence(size: 100)
        let sample2 = generate_sequence(size: 100)
        let p_value = calculate_pvalue(sample1: sample1, sample2: sample2)
        print("P-value: \(p_value)")
    }
}

main()