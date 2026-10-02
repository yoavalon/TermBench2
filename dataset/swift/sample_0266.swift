class Simulation {
    var state: Double

    init(state: Double) {
        self.state = state
    }

    func updateState(change: Double) {
        self.state += change
    }

    func isStable() -> Bool {
        return abs(self.state) < 0.01
    }
}

class BoundaryConditions {
    let minVal: Double
    let maxVal: Double

    init(minVal: Double, maxVal: Double) {
        self.minVal = minVal
        self.maxVal = maxVal
    }

    func enforceBoundaries(state: Double) -> Double {
        if state < minVal {
            return minVal
        } else if state > maxVal {
            return maxVal
        }
        return state
    }
}

class Controller {
    let simulation: Simulation
    let boundaryConditions: BoundaryConditions

    init(simulation: Simulation, boundaryConditions: BoundaryConditions) {
        self.simulation = simulation
        self.boundaryConditions = boundaryConditions
    }

    func run() {
        let change = 0.1
        while true {
            self.simulation.updateState(change: change)
            self.simulation.state = self.boundaryConditions.enforceBoundaries(state: self.simulation.state)
            if self.simulation.isStable() {
                break
            }
        }
    }
}

func main() {
    let simulation = Simulation(state: 0.0)
    let boundaryConditions = BoundaryConditions(minVal: -1.0, maxVal: 1.0)
    let controller = Controller(simulation: simulation, boundaryConditions: boundaryConditions)
    controller.run()
}

main()