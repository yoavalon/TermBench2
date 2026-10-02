import Foundation

class SequenceSimulator {
    var a: Double
    var b: Double
    var n: Int
    var sequence: [Double]

    init(a: Double, b: Double, n: Int) {
        self.a = a
        self.b = b
        self.n = n
        self.sequence = []
    }

    func generateSequence() {
        for i in 0..<n {
            let value = a + Double(i) * b
            sequence.append(value)
        }
    }

    func calculateThermodynamicStates() -> [Double] {
        var states: [Double] = []
        for value in sequence {
            let state = exp(-value)
            states.append(state)
        }
        return states
    }
}

class DataAnalyzer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func average() -> Double {
        return data.reduce(0, +) / Double(data.count)
    }

    func maxValue() -> Double {
        return data.max() ?? 0
    }

    func minValue() -> Double {
        return data.min() ?? 0
    }
}

func main() {
    let a = 0.0
    let b = 0.1
    let n = 100
    let simulator = SequenceSimulator(a: a, b: b, n: n)
    simulator.generateSequence()
    let states = simulator.calculateThermodynamicStates()
    let analyzer = DataAnalyzer(data: states)
    print("Average State:", analyzer.average())
    print("Max State:", analyzer.maxValue())
    print("Min State:", analyzer.minValue())
}

main()