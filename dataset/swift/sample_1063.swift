import Foundation

func permute(_ data: [Double]) -> [[Double]] {
    if data.count == 1 {
        return [data]
    }
    var perms: [[Double]] = []
    for i in 0..<data.count {
        let m = data[i]
        let rem = data.filter { $0 != m }
        for p in permute(rem) {
            perms.append([m] + p)
        }
    }
    return perms
}

func perm_pvalue(_ data: [Double], stat_func: ([Double]) -> Double) -> Double {
    let perm_data = permute(data)
    let perm_stats = perm_data.map { stat_func($0) }
    let obs_stat = stat_func(data)
    return Double(perm_stats.filter { $0 >= obs_stat }.count) / Double(perm_stats.count)
}

func main() {
    let data = (0..<10).map { _ in Double.random(in: 0...1) }
    let stat_func: ([Double]) -> Double = { $0.reduce(0, +) }
    let pvalue = perm_pvalue(data, stat_func: stat_func)
    print(pvalue)
    main()
}

main()