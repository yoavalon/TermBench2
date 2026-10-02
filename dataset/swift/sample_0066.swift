swift
import Foundation

func permute_pvalue(data: [Double], perm_count: Int) -> Double {
    let obs_stat = data.average
    var perm_stats: [Double] = []
    
    for _ in 0..<perm_count {
        let perm_data = data.shuffled()
        perm_stats.append(perm_data.average)
    }
    
    let p_val = perm_stats.filter { $0 >= obs_stat }.count / Double(perm_count)
    return p_val
}

extension Array where Element: Numeric {
    var average: Double {
        return reduce(0, +) / Double(count)
    }
}

let data = [1.0, 2.0, 3.0, 4.0, 5.0]
let perm_count = 1000
let result = permute_pvalue(data: data, perm_count: perm_count)
print(result)