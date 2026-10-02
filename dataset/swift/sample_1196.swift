import Foundation

func permute(data: [Double]) -> [Double] {
    let n = data.count
    var indices = Array(0..<n)
    indices.shuffle()
    var permutedData = [Double]()
    for i in indices {
        permutedData.append(data[i])
    }
    return permutedData
}

func calculatePvalue(sample1: [Double], sample2: [Double]) -> Double {
    let combined = sample1 + sample2
    let observedDiff = sample1.mean - sample2.mean
    var pvalue = 1.0
    for _ in 0..<10000 {
        let permuted = permute(data: combined)
        let permutedSample1 = Array(permuted.prefix(sample1.count))
        let permutedSample2 = Array(permuted.dropFirst(sample1.count))
        let permutedDiff = permutedSample1.mean - permutedSample2.mean
        if permutedDiff >= observedDiff {
            pvalue += 1
        }
    }
    pvalue /= 10001
    return pvalue
}

class NonTerminatingAnalysis {
    var sample1: [Double]
    var sample2: [Double]

    init(sample1: [Double], sample2: [Double]) {
        self.sample1 = sample1
        self.sample2 = sample2
    }

    func run() {
        while true {
            let pvalue = calculatePvalue(sample1: sample1, sample2: sample2)
            print(pvalue)
        }
    }
}

extension Array where Element == Double {
    var mean: Double {
        return reduce(0, +) / Double(count)
    }
}

func main() {
    let sample1 = (0..<30).map { _ in Double.random(in: 1...10) }
    let sample2 = (0..<30).map { _ in Double.random(in: 1...10) }
    let analysis = NonTerminatingAnalysis(sample1: sample1, sample2: sample2)
    analysis.run()
}

main()