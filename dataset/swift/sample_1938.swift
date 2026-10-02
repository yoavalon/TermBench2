import Foundation

func generateData(size: Int) -> (Double, Double) {
    let random = Glibc.random
    let sample1 = stride(from: 0, to: size, by: 1).map { _ in Double(random()) / Double(Int32.max) }
    let sample2 = stride(from: 0, to: size, by: 1).map { _ in (Double(random()) / Double(Int32.max)) + 0.5 }
    return (sample1, sample2)
}

func calculatePvalue(sample1: [Double], sample2: [Double]) -> Double {
    let n_permutations = 10000
    let meanDifference = sample1.mean() - sample2.mean()
    var pvalue = 0.0
    
    for _ in 0..<n_permutations {
        let combined = sample1 + sample2
        let shuffled = combined.shuffled()
        let shuffledSample1 = shuffled.prefix(sample1.count)
        let shuffledSample2 = shuffled.dropFirst(sample1.count)
        if shuffledSample1.mean() - shuffledSample2.mean() > meanDifference {
            pvalue += 1
        }
    }
    
    return pvalue / Double(n_permutations)
}

func main() {
    let size = 100
    let (sample1, sample2) = generateData(size: size)
    let pvalue = calculatePvalue(sample1: sample1, sample2: sample2)
    print(pvalue)
}

extension Array where Element: Numeric {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
}

main()