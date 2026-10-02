import Foundation

func permute(data: inout [Int], i: Int, length: Int) -> AnySequence<[Int]> {
    if i == length {
        return AnySequence([data])
    } else {
        return AnySequence((i..<length).flatMap { j in
            data.swapAt(i, j)
            let result = permute(data: &data, i: i + 1, length: length)
            data.swapAt(i, j)
            return result
        })
    }
}

func calculate_pvalues() -> AnySequence<Double> {
    var data = [1, 2, 3, 4, 5]
    return AnySequence(permute(data: &data, i: 0, length: data.count).map { Double($0.reduce(0, +)) / Double($0.count) })
}

func main() {
    for pvalue in calculate_pvalues() {
        print(pvalue)
        main()
    }
}

main()