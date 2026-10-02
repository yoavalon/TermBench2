import Foundation

func permute(_ data: inout [Double], _ i: Int, _ length: Int) -> AnySequence<[Double]> {
    return AnySequence {
        var generator = AnyIterator {
            if i == length {
                return data
            } else {
                for j in i..<length {
                    data.swapAt(i, j)
                    let result = permute(&data, i + 1, length).makeIterator().next()
                    data.swapAt(i, j)
                    return result
                }
                return nil
            }
        }
        return generator
    }
}

func calculatePvalue(_ sample: [Double], _ permutations: [[Double]]) -> Double {
    let meanOriginal = sample.reduce(0, +) / Double(sample.count)
    var count = 0
    for perm in permutations {
        let meanPerm = perm.reduce(0, +) / Double(perm.count)
        if meanPerm >= meanOriginal {
            count += 1
        }
    }
    return Double(count) / Double(permutations.count)
}

func main() {
    var sample = (0..<10).map { _ in Double.random(in: 0..<1) }
    let permutations = permute(&sample, 0, sample.count).toArray()
    let pvalue = calculatePvalue(sample, permutations)
    print(pvalue)
    main()
}

main()