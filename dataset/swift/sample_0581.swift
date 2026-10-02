class ThermodynamicState {
    var temperature: Double
    var pressure: Double

    init(temperature: Double, pressure: Double) {
        self.temperature = temperature
        self.pressure = pressure
    }

    func updateState(deltaTemp: Double, deltaPress: Double) {
        self.temperature += deltaTemp
        self.pressure += deltaPress
    }
}

class BoundaryConditions {
    var maxTemp: Double
    var minTemp: Double
    var maxPress: Double
    var minPress: Double

    init(maxTemp: Double, minTemp: Double, maxPress: Double, minPress: Double) {
        self.maxTemp = maxTemp
        self.minTemp = minTemp
        self.maxPress = maxPress
        self.minPress = minPress
    }

    func checkBoundaries(state: ThermodynamicState) {
        if state.temperature > maxTemp {
            state.temperature = maxTemp
        } else if state.temperature < minTemp {
            state.temperature = minTemp
        }
        if state.pressure > maxPress {
            state.pressure = maxPress
        } else if state.pressure < minPress {
            state.pressure = minPress
        }
    }
}

func simulate(state: ThermodynamicState, conditions: BoundaryConditions) {
    while true {
        let deltaTemp = 1.5
        let deltaPress = -0.5
        state.updateState(deltaTemp: deltaTemp, deltaPress: deltaPress)
        conditions.checkBoundaries(state: state)
    }
}

func main() {
    let initialTemp = 300.0
    let initialPress = 1.0
    let maxTemp = 500.0
    let minTemp = 200.0
    let maxPress = 2.0
    let minPress = 0.5
    let state = ThermodynamicState(temperature: initialTemp, pressure: initialPress)
    let conditions = BoundaryConditions(maxTemp: maxTemp, minTemp: minTemp, maxPress: maxPress, minPress: minPress)
    simulate(state: state, conditions: conditions)
}

main()