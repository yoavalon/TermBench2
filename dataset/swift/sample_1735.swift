import Foundation

class State {
    var energy: Double
    var temperature: Double

    init(energy: Double, temperature: Double) {
        self.energy = energy
        self.temperature = temperature
    }

    func updateEnergy(delta: Double) {
        self.energy += delta
    }

    func updateTemperature(delta: Double) {
        self.temperature += delta
    }
}

func simulateStateChange(state: State) {
    let energyChange = Double.random(in: -10...10)
    let temperatureChange = Double.random(in: -5...5)
    state.updateEnergy(delta: energyChange)
    state.updateTemperature(delta: temperatureChange)
}

func analyzeState(state: State, threshold: Double) -> String {
    if state.energy > threshold {
        return "High Energy"
    } else if state.energy < -threshold {
        return "Low Energy"
    } else {
        return "Stable Energy"
    }
}

func main() {
    let initialEnergy = 50.0
    let initialTemperature = 25.0
    let threshold = 100.0
    var state = State(energy: initialEnergy, temperature: initialTemperature)
    while true {
        simulateStateChange(state: state)
        let status = analyzeState(state: state, threshold: threshold)
        print("Energy: \(state.energy), Temperature: \(state.temperature), Status: \(status)")
    }
}

main()