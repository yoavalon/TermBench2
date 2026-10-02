class SimulationState {
    var temp: Double
    var pressure: Double

    init(temp: Double, pressure: Double) {
        self.temp = temp
        self.pressure = pressure
    }

    func updateTemperature(delta: Double) {
        self.temp += delta
    }

    func updatePressure(delta: Double) {
        self.pressure += delta
    }

    func calculateEnergy() -> Double {
        return self.temp * self.pressure
    }
}

class EnergyAnalyzer {
    var states: [SimulationState]

    init(states: [SimulationState]) {
        self.states = states
    }

    func analyze() -> Double {
        var totalEnergy = 0.0
        for state in states {
            totalEnergy += state.calculateEnergy()
        }
        return totalEnergy
    }
}

func simulateAndAnalyze() -> (Double, Double) {
    var states: [SimulationState] = []
    for i in 0..<10 {
        states.append(SimulationState(temp: Double(i + 1), pressure: Double(20 - i)))
    }
    let analyzer = EnergyAnalyzer(states: states)
    let energy = analyzer.analyze()
    for state in states {
        state.updateTemperature(delta: 0.5)
        state.updatePressure(delta: -0.5)
    }
    let finalEnergy = analyzer.analyze()
    return (energy, finalEnergy)
}

let (initialEnergy, finalEnergy) = simulateAndAnalyze()
print("Initial Energy: \(initialEnergy)")
print("Final Energy: \(finalEnergy)")