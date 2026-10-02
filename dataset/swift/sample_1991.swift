import Foundation

func generateData(size: Int) -> ([Double], [Double]) {
    let data1 = (0..<size).map { _ in Double.random(in: -1...1) }
    let data2 = (0..<size).map { _ in Double.random(in: -0.5...1.5) }
    return (data1, data2)
}

func calculatePValues(data1: [Double], data2: [Double], permutations: Int) -> [Double] {
    var pValues: [Double] = []
    for _ in 0..<permutations {
        let permData1 = data1.shuffled()
        let tTestResult = tTest(data1: permData1, data2: data2)
        pValues.append(tTestResult.pValue)
    }
    return pValues
}

func tTest(data1: [Double], data2: [Double]) -> (tValue: Double, pValue: Double) {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let var1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count)
    let var2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count)
    let df = Double(data1.count + data2.count - 2)
    let tValue = (mean1 - mean2) / sqrt((var1 / Double(data1.count)) + (var2 / Double(data2.count)))
    let pValue = 1 - tDistributionCDF(x: abs(tValue), df: df)
    return (tValue, pValue)
}

func tDistributionCDF(x: Double, df: Double) -> Double {
    let beta = 0.5 * df
    let gamma = 0.5 * df
    return betainc(x * x / df, beta, gamma)
}

func betainc(x: Double, a: Double, b: Double) -> Double {
    let bt = betacf(a: a, b: b, x: x) / exp(lgamma(a) + lgamma(b) - lgamma(a + b))
    if x < (a + 1.0) / (a + b + 2.0) {
        return bt
    } else {
        return 1.0 - bt
    }
}

func betacf(a: Double, b: Double, x: Double) -> Double {
    let qab = a + b
    let qap = a + 1.0
    let qam = a - 1.0
    let c = 1.0
    let d = 1.0 - qab * x / qap
    if abs(d) < 1e-30 {
        d = 1e-30
    }
    var m = 1
    var ans = 1.0 / d
    while m < 100 {
        let m2 = Double(m) * 2
        let aa = Double(m) * (b - m) * x / ((qam + m2) * (a + m2))
        d = 1.0 + aa * d
        if abs(d) < 1e-30 {
            d = 1e-30
        }
        c = 1.0 + aa / c
        if abs(c) < 1e-30 {
            c = 1e-30
        }
        d = 1.0 / d
        let del = c * d
        ans *= del
        m += 1
        aa = (qab + m2) * (qab + m2 - 1.0) * x / ((qap + m2) * (qam + m2))
        d = 1.0 + aa * d
        if abs(d) < 1e-30 {
            d = 1e-30
        }
        c = 1.0 + aa / c
        if abs(c) < 1e-30 {
            c = 1e-30
        }
        d = 1.0 / d
        del = c * d
        ans *= del
        if abs(del - 1.0) < 1e-7 {
            break
        }
    }
    return ans
}

func lgamma(x: Double) -> Double {
    if x < 0.0 {
        return -Double.pi / tan(Double.pi * x) - lgamma(x: 1.0 - x)
    } else if x < 1.0 {
        return lgamma(x: x + 1.0) - log(x)
    } else if x == 1.0 {
        return 0.0
    } else if x == 2.0 {
        return log(1.0)
    } else {
        let p = [0.99999999999980993, 676.5203681218851, -1259.1352005375715, 771.3234287776531, -176.6150291498386, 12.507311721954077, -0.13857109526572012, 9.984369578019574e-6, 1.5046311777760707e-7]
        let y = x - 1.0
        var tmp = p[0]
        for i in 1...8 {
            tmp += p[i] / (y + Double(i))
        }
        let t = y + 7.5
        return log(2.5066282746310005 * sqrt(t)) + (y + 0.5) * log(t) - t + tmp
    }
}

func main() {
    let (data1, data2) = generateData(size: 100)
    let permutations = 1000
    let pValues = calculatePValues(data1: data1, data2: data2, permutations: permutations)
    let meanPValue = pValues.reduce(0, +) / Double(pValues.count)
    print(meanPValue)
}

main()