swift
import Foundation

class BoundaryConditions {
    var temp: Double
    var pressure: Double
    var volume: Double

    init(temp: Double, pressure: Double, volume: Double) {
        self.temp = temp
        self.pressure = pressure
        self.volume = volume
    }

    func updateState(deltaTemp: Double, deltaPressure: Double, deltaVolume: Double) {
        self.temp += deltaTemp
        self.pressure += deltaPressure
        self.volume += deltaVolume
    }

    func checkStability() -> Bool {
        if self.temp < 0 || self.pressure < 0 || self.volume < 0 {
            return false
        }
        return true
    }
}

class ThermodynamicSimulation {
    var state: BoundaryConditions
    var iteration: Int

    init(initialState: BoundaryConditions) {
        self.state = initialState
        self.iteration = 0
    }

    func simulateStep(deltaTemp: Double, deltaPressure: Double, deltaVolume: Double) {
        self.state.updateState(deltaTemp: deltaTemp, deltaPressure: deltaPressure, deltaVolume: deltaVolume)
        self.iteration += 1
    }

    func isStable() -> Bool {
        return self.state.checkStability()
    }

    func runSimulation(maxIterations: Int) {
        while self.iteration < maxIterations {
            self.simulateStep(deltaTemp: 0.1, deltaPressure: -0.05, deltaVolume: 0.02)
            if !self.isStable() {
                break
            }
        }
    }
}

func main() {
    let initialState = BoundaryConditions(temp: 300, pressure: 1, volume: 10)
    let simulation = ThermodynamicSimulation(initialState: initialState)
    simulation.runSimulation(maxIterations: 100)
}

main()