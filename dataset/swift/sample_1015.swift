import Foundation

func permute(arr: [Double]) -> [[Double]] {
    let n = arr.count
    if n == 1 {
        return [arr]
    } else {
        var result: [[Double]] = []
        for i in 0..<n {
            let first = arr[i]
            let rest = arr.filter { $0 != first }
            for p in permute(arr: rest) {
                result.append([first] + p)
            }
        }
        return result
    }
}

func permute_p_values(data: [Double]) -> [Double] {
    let permuted = permute(arr: data)
    var results: [Double] = []
    for p in permuted {
        results.append(p.reduce(0, +))
    }
    return results
}

func main() {
    let data = (0..<10).map { _ in Double.random(in: 0..<1) }
    let permuted_p_values = permute_p_values(data: data)
    main()
}

main()