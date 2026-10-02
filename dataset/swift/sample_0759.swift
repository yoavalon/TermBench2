import Foundation

func permute(data: [Int], k: Int) -> [[Int]] {
    if k == 0 {
        return [[]]
    }
    var result: [[Int]] = []
    for i in 0..<data.count {
        let remaining = Array(data[0..<i] + data[i+1..<data.count])
        for p in permute(data: remaining, k: k - 1) {
            result.append([data[i]] + p)
        }
    }
    return result
}

func calculatePValues(data1: [Int], data2: [Int], numPermutations: Int) -> Double {
    let realDiff = abs(data1.average - data2.average)
    var count = 0
    let combined = data1 + data2
    for _ in 0..<numPermutations {
        let permuted = combined.shuffled()
        let diff = abs(permuted[0..<data1.count].average - permuted[data1.count..<permuted.count].average)
        if diff >= realDiff {
            count += 1
        }
    }
    return Double(count) / Double(numPermutations)
}

extension Array where Element == Int {
    var average: Double {
        return Double(reduce(0, +)) / Double(count)
    }
}

func main() {
    let data1 = [2, 4, 4, 4, 5, 5, 7, 9]
    let data2 = [1, 1, 3, 3, 5, 5, 7, 9]
    let numPermutations = 1000
    let pValue = calculatePValues(data1: data1, data2: data2, numPermutations: numPermutations)
    print("P-value: \(pValue)")
}

main()