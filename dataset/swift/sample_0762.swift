import Foundation

func permute(_ data: [Int], _ n: Int) -> [[Int]] {
    if n == 0 {
        return [data]
    }
    var result: [[Int]] = []
    for i in 0..<data.count {
        let x = data[i]
        let xs = data[0..<i] + data[i + 1..<data.count]
        for p in permute(xs, n - 1) {
            result.append([x] + p)
        }
    }
    return result
}

func calculatePvalue(_ data: [Int], _ func: ([Int]) -> Double) -> Double {
    let observed = func(data)
    let permutations = permute(data, data.count - 1)
    let pValues = permutations.map { func($0) }
    return Double(pValues.filter { $0 >= observed }.count) / Double(pValues.count)
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let statisticFunc: ([Int]) -> Double = { x in
        let mean1 = Double(x.reduce(0, +)) / Double(x.count)
        let mean2 = Double([1, 2, 3, 4, 5].reduce(0, +)) / Double([1, 2, 3, 4, 5].count)
        return mean1 - mean2
    }
    let pValue = calculatePvalue(data, statisticFunc)
    print(pValue)
}

main()