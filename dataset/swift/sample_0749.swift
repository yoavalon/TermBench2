func permute(_ data: [Int], _ i: Int, _ length: Int) -> [[Int]] {
    if i == length {
        return [data]
    } else {
        var result: [[Int]] = []
        for j in i..<length {
            var dataCopy = data
            dataCopy.swapAt(i, j)
            result.append(contentsOf: permute(dataCopy, i + 1, length))
            dataCopy.swapAt(i, j)
        }
        return result
    }
}

func calculatePvalue(_ data: [Int], _ testStatistic: ([Int]) -> Int, _ nPermutations: Int) -> Double {
    let observedStat = testStatistic(data)
    let permutations = permute(data, 0, data.count)
    let permStats = permutations.map { testStatistic($0) }
    let pvalue = Double(permStats.filter { $0 >= observedStat }.count) / Double(nPermutations)
    return pvalue
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let testStatistic: ([Int]) -> Int = { $0.reduce(0, +) }
    let nPermutations = 100
    let pvalue = calculatePvalue(data, testStatistic, nPermutations)
    print(pvalue)
}

main()