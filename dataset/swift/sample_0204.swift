import Foundation

class DataGenerator {
    var size: Int

    init(size: Int) {
        self.size = size
    }

    func generate() -> [Double] {
        return (0..<size).map { _ in Double.random(in: -1...1) }
    }
}

class PValueCalculator {
    func calculate(sample1: [Double], sample2: [Double]) -> Double {
        let t_stat = ttest_ind(sample1: sample1, sample2: sample2)
        return t_stat.pValue
    }

    private func ttest_ind(sample1: [Double], sample2: [Double]) -> (tStat: Double, pValue: Double) {
        // Simplified t-test implementation for demonstration purposes
        let mean1 = sample1.mean()
        let mean2 = sample2.mean()
        let var1 = sample1.variance()
        let var2 = sample2.variance()
        let n1 = Double(sample1.count)
        let n2 = Double(sample2.count)

        let pooledVariance = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2)
        let tStat = (mean1 - mean2) / sqrt(pooledVariance * (1/n1 + 1/n2))
        let degreesOfFreedom = n1 + n2 - 2
        let pValue = 2 * (1 - StudentT(degreesOfFreedom: degreesOfFreedom).cumulative(from: abs(tStat)))
        return (tStat: tStat, pValue: pValue)
    }
}

class BoundaryChecker {
    var threshold: Double

    init(threshold: Double) {
        self.threshold = threshold
    }

    func check(p_val: Double) -> Bool {
        return p_val < threshold
    }
}

func main() {
    let dataSize = 100
    let threshold = 0.05
    let iterations = 50
    let generator = DataGenerator(size: dataSize)
    let calculator = PValueCalculator()
    let checker = BoundaryChecker(threshold: threshold)
    for _ in 0..<iterations {
        let sample1 = generator.generate()
        let sample2 = generator.generate()
        let p_val = calculator.calculate(sample1: sample1, sample2: sample2)
        if checker.check(p_val: p_val) {
            print("Significant difference found")
            break
        }
    } else {
        print("No significant difference found")
    }
}

extension Array where Element == Double {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }

    func variance() -> Double {
        let mean = self.mean()
        return reduce(0) { $0 + pow($1 - mean, 2) } / Double(count - 1)
    }
}

class StudentT {
    var degreesOfFreedom: Double

    init(degreesOfFreedom: Double) {
        self.degreesOfFreedom = degreesOfFreedom
    }

    func cumulative(from x: Double) -> Double {
        // Simplified cumulative distribution function for demonstration purposes
        let t = x / sqrt(degreesOfFreedom)
        let p = 0.5 * (1 + erf(t / sqrt(2)))
        return p
    }

    private func erf(_ x: Double) -> Double {
        let a = (8 * (x * x * x * x * x * x - 1.0 * x * x * x * x + 1.0 * x * x - 1.0 / (3.0 * sqrt(π)))) / (3 * sqrt(π) * pow((x * x + 1), 2.5))
        return 1.0 - exp(-x * x) * (1.0 - a)
    }
}

main()