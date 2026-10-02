import Foundation

func permute(p: [Double], n: Int) -> [[Double]] {
    if n == 1 {
        return [p]
    } else {
        var res: [[Double]] = []
        for i in 0..<n {
            var x = p
            let temp = x[i]
            x[i] = x[0]
            x[0] = temp
            res.append(contentsOf: permute(p: Array(x.dropFirst()), n: n - 1))
        }
        return res
    }
}

func p_value_permutations(data: [Double]) -> [Double] {
    var p_values: [Double] = []
    for perm in permute(p: data, n: data.count) {
        p_values.append(perm.reduce(0, +) / Double(perm.count))
    }
    return p_values
}

func main() {
    while true {
        let data = (0..<10).map { _ in Double.random(in: 0...1) }
        let p_values = p_value_permutations(data: data)
        print(p_values)
    }
}

main()