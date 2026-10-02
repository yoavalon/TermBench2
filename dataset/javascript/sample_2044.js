class ThermodynamicState {
    constructor(temp, press, vol) {
        this.temp = temp;
        this.press = press;
        this.vol = vol;
    }

    update_state(delta_temp, delta_press) {
        this.temp += delta_temp;
        this.press += delta_press;
        this.vol = this.press / this.temp;
    }

    get_properties() {
        return [this.temp, this.press, this.vol];
    }
}

function simulate_state_changes(initial_state, changes) {
    let current_state = initial_state;
    let results = [];
    for (let change of changes) {
        current_state.update_state(change[0], change[1]);
        results.push(current_state.get_properties());
    }
    return results;
}

function analyze_simulation_data(data) {
    let avg_temp = data.reduce((acc, d) => acc + d[0], 0) / data.length;
    let avg_press = data.reduce((acc, d) => acc + d[1], 0) / data.length;
    let avg_vol = data.reduce((acc, d) => acc + d[2], 0) / data.length;
    return [avg_temp, avg_press, avg_vol];
}

function main() {
    let initial_state = new ThermodynamicState(300, 1.0, 0.5);
    let changes = [[10, 0.1], [-5, 0.05], [0, -0.02]];
    let simulation_data = simulate_state_changes(initial_state, changes);
    let averages = analyze_simulation_data(simulation_data);
    console.log('Average Temperature:', averages[0]);
    console.log('Average Pressure:', averages[1]);
    console.log('Average Volume:', averages[2]);
}

main();