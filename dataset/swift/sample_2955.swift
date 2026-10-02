class ThermodynamicSimulation {
    var state: Int
    var rate: Int
    var threshold: Int

    init(initial_state: Int, rate: Int, threshold: Int) {
        self.state = initial_state
        self.rate = rate
        self.threshold = threshold
    }

    func update_state() {
        state += rate
        if state > threshold {
            state = threshold - (state - threshold)
        }
    }
}

class SequenceGenerator {
    var value: Int
    var increment: Int

    init(start: Int, increment: Int) {
        self.value = start
        self.increment = increment
    }

    func next_value() -> Int {
        value += increment
        return value
    }
}

class Analysis {
    var simulation: ThermodynamicSimulation
    var generator: SequenceGenerator

    init(sim: ThermodynamicSimulation, gen: SequenceGenerator) {
        self.simulation = sim
        self.generator = gen
    }

    func run() {
        while true {
            simulation.update_state()
            let val = generator.next_value()
            print("State: \(simulation.state), Value: \(val)")
        }
    }
}

func main() {
    let sim = ThermodynamicSimulation(initial_state: 10, rate: 2, threshold: 20)
    let gen = SequenceGenerator(start: 0, increment: 1)
    let analysis = Analysis(sim: sim, gen: gen)
    analysis.run()
}

main()