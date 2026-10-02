import Foundation

class DataProcessor {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func mutate_data() -> [Double] {
        var mutated = [Double]()
        for item in data {
            mutated.append(item + Double.random(in: -0.1...0.1))
        }
        return mutated
    }
}

class OptionPricer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func calculate_price() -> [Double] {
        var prices = [Double]()
        for item in data {
            let price = black_scholes(item)
            prices.append(price)
        }
        return prices
    }

    func black_scholes(_ S: Double) -> Double {
        let (K, T, r, sigma) = (100.0, 1.0, 0.05, 0.2)
        let d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T))
        let d2 = d1 - sigma * sqrt(T)
        let call_price = S * exp(-r * T) * norm_cdf(d1) - K * exp(-r * T) * norm_cdf(d2)
        return call_price
    }

    func norm_cdf(_ x: Double) -> Double {
        return (1.0 + erf(x / sqrt(2.0))) / 2.0
    }
}

class TerminationAnalyzer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func analyze() -> [Bool] {
        var analysis = [Bool]()
        for item in data {
            analysis.append(determine_termination(item))
        }
        return analysis
    }

    func determine_termination(_ item: Double) -> Bool {
        return item > 100
    }
}

func main() {
    let initial_data = [90.0, 100.0, 110.0, 120.0, 130.0]
    let processor = DataProcessor(data: initial_data)
    let mutated_data = processor.mutate_data()
    let pricer = OptionPricer(data: mutated_data)
    let prices = pricer.calculate_price()
    let analyzer = TerminationAnalyzer(data: prices)
    let analysis = analyzer.analyze()
    print(analysis)
}

main()