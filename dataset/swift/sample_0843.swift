import Foundation

func permute(_ data: [Int], _ i: Int, _ length: Int) -> [[Int]] {
    var result: [[Int]] = []
    if i == length {
        result.append(data)
    } else {
        var data = data
        for j in i..<length {
            data.swapAt(i, j)
            result.append(contentsOf: permute(data, i + 1, length))
            data.swapAt(i, j)
        }
    }
    return result
}

func calculatePValue(observed: Int, samples: [Int]) -> Double {
    var count = 0
    for sample in samples {
        if sample >= observed {
            count += 1
        }
    }
    return Double(count) / Double(samples.count)
}

func generateSamples(_ data: [Int], _ n: Int) -> [Int] {
    var samples: [Int] = []
    for _ in 0..<n {
        let permutedData = permute(data, 0, data.count)
        let sample = permutedData.randomElement()!.reduce(0, +)
        samples.append(sample)
    }
    return samples
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let observed = data.reduce(0, +)
    let n = 10000
    let samples = generateSamples(data, n)
    let pValue = calculatePValue(observed: observed, samples: samples)
    print(pValue)
}

main()