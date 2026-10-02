swift
import Foundation

func permute_pvalues(data: [Double], n: Int) -> [Double] {
    if n == 0 {
        return [0]
    } else {
        let permuted = data.shuffled()
        return [permuted.reduce(0, +) / Double(permuted.count)] + permute_pvalues(data: data, n: n - 1)
    }
}

func main() {
    let data = [0.05, 0.03, 0.07, 0.1]
    let n = 1000
    let results = permute_pvalues(data: data, n: n)
    print(results.last!)
}

main()