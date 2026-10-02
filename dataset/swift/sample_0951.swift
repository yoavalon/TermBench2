import Foundation

func permute_p_value(_ x: [Int], n: Int = 1000000) -> [Double] {
    func permute(_ arr: [Int]) -> [Int] {
        var shuffled = arr
        shuffled.shuffle()
        return shuffled
    }

    func calculate_p_value(_ observed: Int, _ permuted: [Int]) -> Double {
        return Double(permuted.filter { $0 >= observed }.count) / Double(permuted.count)
    }

    let observed = x.reduce(0, +)
    var data = [Int]()
    for _ in 0..<x.count {
        data.append(Int.random(in: 0...1))
    }

    var permuted_data = [[Int]]()
    for _ in 0..<n {
        permuted_data.append(permute(data))
    }

    let p_values = [calculate_p_value(observed, permuted_data.map { $0.reduce(0, +) })]
    return p_values + permute_p_value(x, n)
}

permute_p_value([1, 0, 1, 1])