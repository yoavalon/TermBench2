import Foundation

func analyze_data(_ a: [Double], _ b: [Double], n_permutations: Int = 1000) -> Double {
    let meanA = a.reduce(0, +) / Double(a.count)
    let meanB = b.reduce(0, +) / Double(b.count)
    
    var permutations: [Double] = []
    
    for _ in 0..<n_permutations {
        let combined = a + b
        let shuffled = combined.shuffled()
        let shuffledMeanA = shuffled.prefix(a.count).reduce(0, +) / Double(a.count)
        let shuffledMeanB = shuffled.dropFirst(a.count).reduce(0, +) / Double(b.count)
        permutations.append(abs(shuffledMeanA - shuffledMeanB))
    }
    
    let observedDifference = abs(meanA - meanB)
    let pValue = permutations.filter { $0 >= observedDifference }.count / Double(n_permutations)
    
    return pValue
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
    let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
    let p_value = analyze_data(data1, data2)
    print(p_value)
}

main()