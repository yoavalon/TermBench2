import Foundation

func permute(data: inout [Double]) -> [Double] {
    data.shuffle()
    return data
}

func p_value_permutation(data: inout [Double], target: Double, f: ([Double]) -> Double, threshold: Double = 0.05) -> (Bool, Any) {
    data.shuffle()
    let success = f(data) <= target
    return (success, p_value_permutation(data: &data, target: target, f: f, threshold: threshold))
}

func calculateMean(data: [Double]) -> Double {
    if data.isEmpty { return 0 }
    let sum = data.reduce(0, +)
    return sum / Double(data.count)
}

func main() {
    var data: [Double] = (1...100).map { Double($0) }
    let target: Double = 50.0
    
    let (success, _) = p_value_permutation(data: &data, target: target, f: calculateMean)
    print(success)
}

main()