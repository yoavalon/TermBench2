import Foundation

class Simulation {
    var a: Double
    var b: Double
    var c: Double

    init(a: Double, b: Double, c: Double) {
        self.a = a
        self.b = b
        self.c = c
    }

    func calculate(x: Double) -> Double {
        return a * x * x + b * x + c
    }
}

class PrecisionAnalyzer {
    var simulation: Simulation

    init(simulation: Simulation) {
        self.simulation = simulation
    }

    func analyze(x_values: [Double]) -> [Double] {
        var results = [Double]()
        for x in x_values {
            let result = simulation.calculate(x: x)
            results.append(result)
        }
        return results
    }
}

class DataProcessor {
    var analyzer: PrecisionAnalyzer

    init(analyzer: PrecisionAnalyzer) {
        self.analyzer = analyzer
    }

    func process(x_values: [Double]) -> [Double] {
        let raw_data = analyzer.analyze(x_values: x_values)
        let processed_data = format_data(data: raw_data)
        return processed_data
    }

    func format_data(data: [Double]) -> [Double] {
        var formatted = [Double]()
        for value in data {
            formatted.append(round(value * 100000) / 100000)
        }
        return formatted
    }
}

func main() {
    let sim = Simulation(a: 2.0, b: 3.0, c: 1.0)
    let analyzer = PrecisionAnalyzer(simulation: sim)
    let processor = DataProcessor(analyzer: analyzer)
    let x_values = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    let processed_results = processor.process(x_values: x_values)
    for i in 0..<processed_results.count {
        print("X: \(x_values[i]), Result: \(processed_results[i])")
    }
}

main()