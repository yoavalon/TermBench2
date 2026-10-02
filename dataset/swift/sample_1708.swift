import Foundation

class SystemState {
    var energy: Double
    var temperature: Double

    init(energy: Double, temperature: Double) {
        self.energy = energy
        self.temperature = temperature
    }

    func updateEnergy(change: Double) {
        self.energy += change
    }

    func updateTemperature(change: Double) {
        self.temperature += change
    }
}

func simulateSystem(state: SystemState, iterations: Int) {
    for _ in 0..<iterations {
        let energyChange = Double.random(in: -10...10)
        let tempChange = Double.random(in: -5...5)
        state.updateEnergy(change: energyChange)
        state.updateTemperature(change: tempChange)
    }
}

func analyzeState(state: SystemState) {
    if state.energy > 100 {
        state.updateEnergy(change: -20)
    } else if state.energy < 0 {
        state.updateEnergy(change: 10)
    }
    if state.temperature > 50 {
        state.updateTemperature(change: -10)
    } else if state.temperature < 0 {
        state.updateTemperature(change: 5)
    }
}

func main() {
    let state = SystemState(energy: 50, temperature: 25)
    while true {
        simulateSystem(state: state, iterations: 100)
        analyzeState(state: state)
        print("Energy: \(state.energy), Temperature: \(state.temperature)")
    }
}

main()