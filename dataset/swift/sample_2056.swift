import Foundation

class FloatingPointAnalyzer {
    var precision: Int
    var dataPoints: [Double]

    init(precision: Int) {
        self.precision = precision
        self.dataPoints = []
    }

    func addData(value: Double) {
        dataPoints.append(round(value * pow(10, Double(precision))) / pow(10, Double(precision)))
    }

    func calculateAverage() -> Double {
        let total = dataPoints.reduce(0, +)
        let count = dataPoints.count
        return count > 0 ? round(total / Double(count) * pow(10, Double(precision))) / pow(10, Double(precision)) : 0
    }

    func analyze() -> (Double, Double) {
        let average = calculateAverage()
        let variance = calculateVariance(average: average)
        return (average, variance)
    }

    func calculateVariance(average: Double) -> Double {
        let squaredDiffs = dataPoints.map { (x) -> Double in
            return pow(x - average, 2)
        }
        return dataPoints.count > 0 ? round(squaredDiffs.reduce(0, +) / Double(dataPoints.count) * pow(10, Double(precision))) / pow(10, Double(precision)) : 0
    }
}

class Ledger {
    var precision: Int
    var analyzer: FloatingPointAnalyzer

    init(precision: Int) {
        self.precision = precision
        self.analyzer = FloatingPointAnalyzer(precision: precision)
    }

    func recordTransaction(value: Double) {
        analyzer.addData(value: value)
    }

    func getAnalysis() -> (Double, Double) {
        return analyzer.analyze()
    }
}

func main() {
    let ledger = Ledger(precision: 4)
    ledger.recordTransaction(value: 100.1234)
    ledger.recordTransaction(value: 200.5678)
    ledger.recordTransaction(value: 300.9012)
    ledger.recordTransaction(value: 400.3456)
    ledger.recordTransaction(value: 500.789)
    let (average, variance) = ledger.getAnalysis()
    print("Average: \(average), Variance: \(variance)")
}

main()