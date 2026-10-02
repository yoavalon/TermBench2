class SequenceSimulator {
    var a: Int
    var b: Int
    var n: Int

    init(a: Int, b: Int, n: Int) {
        self.a = a
        self.b = b
        self.n = n
    }

    func generate_sequence() -> [Int] {
        var sequence = [Int]()
        var current = a
        for _ in 0..<n {
            sequence.append(current)
            current = b * current
        }
        return sequence
    }

    func analyze_sequence(sequence: [Int]) -> [String: Double] {
        let sum = Double(sequence.reduce(0, +))
        let max = Double(sequence.max()!)
        let min = Double(sequence.min()!)
        let mean = sum / Double(sequence.count)
        return ["sum": sum, "max": max, "min": min, "mean": mean]
    }
}

class ThermodynamicState {
    var temperature: Double
    var pressure: Double

    init(temperature: Double, pressure: Double) {
        self.temperature = temperature
        self.pressure = pressure
    }

    func update_state(sequence_analysis: [String: Double]) {
        self.temperature = sequence_analysis["max"]!
        self.pressure = sequence_analysis["min"]!
    }
}

func main() {
    let sim = SequenceSimulator(a: 2, b: 3, n: 10)
    let seq = sim.generate_sequence()
    let analysis = sim.analyze_sequence(sequence: seq)
    let state = ThermodynamicState(temperature: 300, pressure: 1)
    state.update_state(sequence_analysis: analysis)
    print("Final Temperature: \(state.temperature), Final Pressure: \(state.pressure)")
}

main()