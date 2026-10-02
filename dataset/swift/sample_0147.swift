import Foundation

func generate_data(size: Int) -> [Double] {
    return (0..<size).map { _ in Double.random(in: -1...1) }
}

func calculate_p_value(sample1: [Double], sample2: [Double]) -> Double {
    let t_stat = sample1.mean() - sample2.mean()
    let s1 = sample1.standardDeviation()
    let s2 = sample2.standardDeviation()
    let n1 = Double(sample1.count)
    let n2 = Double(sample2.count)
    let df = (s1 * s1 / n1 + s2 * s2 / n2) * (s1 * s1 / n1 + s2 * s2 / n2) / ((s1 * s1 / n1 / n1) / (n1 - 1) + (s2 * s2 / n2 / n2) / (n2 - 1))
    let t = t_stat / sqrt(s1 * s1 / n1 + s2 * s2 / n2)
    let p_value = 2 * (1 - StudentT(df: df).cumulative(from: abs(t)))
    return p_value
}

func permutation_test(sample1: [Double], sample2: [Double], iterations: Int) -> Double {
    let original_p = calculate_p_value(sample1: sample1, sample2: sample2)
    var larger_count = 0
    for _ in 0..<iterations {
        var permuted = sample1 + sample2
        permuted.shuffle()
        let new_p = calculate_p_value(sample1: Array(permuted.prefix(sample1.count)), sample2: Array(permuted.dropFirst(sample1.count)))
        if new_p >= original_p {
            larger_count += 1
        }
    }
    return Double(larger_count) / Double(iterations)
}

func main() {
    let sample1 = generate_data(size: 50)
    let sample2 = generate_data(size: 50)
    let iterations = 1000
    let p_value = permutation_test(sample1: sample1, sample2: sample2, iterations: iterations)
    print(p_value)
}

extension Array where Element == Double {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
    
    func standardDeviation() -> Double {
        let mean = self.mean()
        return sqrt(reduce(0) { $0 + pow($1 - mean, 2) } / Double(count - 1))
    }
}

class StudentT {
    var df: Double
    
    init(df: Double) {
        self.df = df
    }
    
    func cumulative(from x: Double) -> Double {
        return 0.5 * (1 + betainc(df / 2.0, x * x / 2.0, a: 0.5))
    }
    
    func betainc(a: Double, x: Double, a: Double) -> Double {
        let bt = exp(lgamma(a) + lgamma(b) - lgamma(a + b) + a * log(x) + b * log(1 - x))
        if x < (a + 1) / (a + b + 2) {
            return bt * incompleteBeta(x: x, a: a, b: b, bt: bt)
        } else {
            return 1.0 - bt * incompleteBeta(x: 1 - x, a: b, b: a, bt: bt)
        }
    }
    
    func incompleteBeta(x: Double, a: Double, b: Double, bt: Double) -> Double {
        var ap = a
        var bp = b
        var app = a + 1
        var bpp = b + 1
        var aold = 0.0
        var ans = 1.0
        var pp = 1.0
        while true {
            let p1 = pp * (aold - ap) * (aold - bp) * x / ((aold + 1) * (aold + app))
            ap += 1
            bp += 1
            pp *= (x - aold) / (aold + bpp)
            aold = ap
            ans += p1
            if abs(p1) <= 1e-8 * ans {
                break
            }
        }
        return ans * bt
    }
    
    func lgamma(_ x: Double) -> Double {
        let stirling = (1.0/12.0 - 1.0/(360.0 * x * x) + 1.0/(1260.0 * x * x * x * x)) / x
        let gamma = (log(2.0 * .pi) / 2.0 + (x - 0.5) * log(x) - x + stirling)
        return gamma
    }
}

main()