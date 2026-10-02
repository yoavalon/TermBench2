import Foundation

func monte_carlo(n: Int, s: Double, r: Double, t: Double, v: Double) -> Double {
    func simulate(i: Int, p: Double) -> Double {
        if i == n {
            return max(p - s, 0)
        }
        let randomValue = Double.random(in: -v...v)
        return simulate(i: i + 1, p: p * (1 + (r + randomValue)))
    }
    var total = 0.0
    for _ in 0..<n {
        total += simulate(i: 0, p: s)
    }
    return total / Double(n)
}

let s = 100.0
let k = 100
let r = 0.05
let t = 1.0
let v = 0.2
let n = 1000

print(monte_carlo(n: n, s: s, r: r, t: t, v: v))