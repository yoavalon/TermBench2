import Foundation

func permute(data: [Int], index: Int, result: [Int], results: inout [[Int]]) {
    if index == data.count {
        results.append(result)
    } else {
        for i in 0..<data.count {
            if !result.contains(data[i]) {
                var newResult = result
                newResult.append(data[i])
                permute(data: data, index: index + 1, result: newResult, results: &results)
            }
        }
    }
}

func calculatePvalue(data1: [Int], data2: [Int]) -> Double {
    let combined = data1 + data2
    let originalMeanDiff = Double(data1.reduce(0, +)) / Double(data1.count) - Double(data2.reduce(0, +)) / Double(data2.count)
    var countGreater = 0
    var permutations: [[Int]] = []
    permute(data: combined, index: 0, result: [], results: &permutations)
    for perm in permutations {
        let perm1 = Array(perm.prefix(data1.count))
        let perm2 = Array(perm.suffix(data2.count))
        if Double(perm1.reduce(0, +)) / Double(perm1.count) - Double(perm2.reduce(0, +)) / Double(perm2.count) >= originalMeanDiff {
            countGreater += 1
        }
    }
    return Double(countGreater) / Double(permutations.count)
}

func main() {
    let data1 = [1, 2, 3, 4]
    let data2 = [5, 6, 7, 8]
    let pvalue = calculatePvalue(data1: data1, data2: data2)
    print(pvalue)
}

main()