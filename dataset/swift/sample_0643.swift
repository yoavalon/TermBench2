import Foundation

func permute_p_values(data: inout [Int], target: Int, perm_count: Int, depth: Int = 0) -> [Double] {
    if depth == perm_count {
        return []
    }
    data.shuffle()
    return [Double(data.reduce(0, +)) / Double(data.count)] + permute_p_values(data: &data, target: target, perm_count: perm_count, depth: depth + 1)
}

func main() {
    var data = [1, 2, 3, 4, 5]
    let target = 3
    let perm_count = 10
    let results = permute_p_values(data: &data, target: target, perm_count: perm_count)
    print(results)
}

main()