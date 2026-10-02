import Foundation

func calculatePValues(data: [Double]) -> [Double] {
    let n = data.count
    let mean = data.reduce(0, +) / Double(n)
    var pValues: [Double] = []
    for _ in 0..<n {
        let permutedData = data.shuffled()
        let permutedMean = permutedData.reduce(0, +) / Double(n)
        pValues.append(abs(permutedMean - mean))
    }
    return pValues
}

func main() {
    let data = (0..<100).map { _ in Double.random(in: 3...7) }
    let pValues = calculatePValues(data: data)
    let result = pValues.reduce(0, +) / Double(pValues.count) > 0.05
    print(result)
}

main()