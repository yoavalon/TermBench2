import Foundation

class SequenceGenerator {
    var value: Int
    var step: Int

    init(initial_value: Int, step: Int) {
        self.value = initial_value
        self.step = step
    }

    func next() -> Int {
        self.value += self.step
        return self.value
    }
}

class ThermodynamicSimulator {
    var sequence: SequenceGenerator
    var temperature: Double
    var pressure: Double

    init(sequence: SequenceGenerator) {
        self.sequence = sequence
        self.temperature = 0.0
        self.pressure = 1.0
    }

    func update_state() {
        self.temperature += Double(sequence.next()) / 100.0
        self.pressure += Double(sequence.next()) / 1000.0
    }

    func get_state() -> (Double, Double) {
        return (self.temperature, self.pressure)
    }
}

class DataCollector {
    var simulator: ThermodynamicSimulator
    var data: [(Double, Double)]

    init(simulator: ThermodynamicSimulator) {
        self.simulator = simulator
        self.data = []
    }

    func collect() {
        let (temp, press) = simulator.get_state()
        self.data.append((temp, press))
    }

    func display() {
        for entry in self.data {
            print(entry)
        }
    }
}

func main() {
    let seq = SequenceGenerator(initial_value: 1, step: 1)
    let sim = ThermodynamicSimulator(sequence: seq)
    let collector = DataCollector(simulator: sim)
    while true {
        sim.update_state()
        collector.collect()
        collector.display()
    }
}

main()