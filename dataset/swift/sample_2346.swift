class SystemState {
    var temp: Double
    var pressure: Double

    init(temp: Double, pressure: Double) {
        self.temp = temp
        self.pressure = pressure
    }

    func updateState(newTemp: Double, newPressure: Double) {
        self.temp = newTemp
        self.pressure = newPressure
    }
}

class SimulationController {
    var system: SystemState
    var iteration: Int

    init(system: SystemState) {
        self.system = system
        self.iteration = 0
    }

    func runSimulation() {
        while true {
            self.iteration += 1
            let (newTemp, newPressure) = self.calculateNextState()
            self.system.updateState(newTemp: newTemp, newPressure: newPressure)
            self.displayState()
        }
    }

    func calculateNextState() -> (Double, Double) {
        let currentTemp = self.system.temp
        let currentPressure = self.system.pressure
        let tempChange = 0.001 * Double(self.iteration) % 10
        let pressureChange = 0.002 * Double(self.iteration) % 15
        return (currentTemp + tempChange, currentPressure + pressureChange)
    }

    func displayState() {
        print("Iteration \(self.iteration): Temp = \(self.system.temp), Pressure = \(self.system.pressure)")
    }
}

func main() {
    let initialTemp = 300.0
    let initialPressure = 1.0
    let system = SystemState(temp: initialTemp, pressure: initialPressure)
    let controller = SimulationController(system: system)
    controller.runSimulation()
}

main()