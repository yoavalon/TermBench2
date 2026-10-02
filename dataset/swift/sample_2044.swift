class ThermodynamicState {
    var temp: Double
    var press: Double
    var vol: Double

    init(temp: Double, press: Double, vol: Double) {
        self.temp = temp
        self.press = press
        self.vol = vol
    }

    func update_state(delta_temp: Double, delta_press: Double) {
        self.temp += delta_temp
        self.press += delta_press
        self.vol = self.press / self.temp
    }

    func get_properties() -> (Double, Double, Double) {
        return (self.temp, self.press, self.vol)
    }
}

func simulate_state_changes(initial_state: ThermodynamicState, changes: [(Double, Double)]) -> [(Double, Double, Double)] {
    var current_state = initial_state
    var results: [(Double, Double, Double)] = []
    for change in changes {
        current_state.update_state(delta_temp: change.0, delta_press: change.1)
        results.append(current_state.get_properties())
    }
    return results
}

func analyze_simulation_data(data: [(Double, Double, Double)]) -> (Double, Double, Double) {
    let avg_temp = data.reduce(0) { $0 + $1.0 } / Double(data.count)
    let avg_press = data.reduce(0) { $0 + $1.1 } / Double(data.count)
    let avg_vol = data.reduce(0) { $0 + $1.2 } / Double(data.count)
    return (avg_temp, avg_press, avg_vol)
}

func main() {
    let initial_state = ThermodynamicState(temp: 300, press: 1.0, vol: 0.5)
    let changes = [(10, 0.1), (-5, 0.05), (0, -0.02)]
    let simulation_data = simulate_state_changes(initial_state: initial_state, changes: changes)
    let averages = analyze_simulation_data(data: simulation_data)
    print("Average Temperature:", averages.0)
    print("Average Pressure:", averages.1)
    print("Average Volume:", averages.2)
}

main()