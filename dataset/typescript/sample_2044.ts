class ThermodynamicState {
    temp: number;
    press: number;
    vol: number;

    constructor(temp: number, press: number, vol: number) {
        this.temp = temp;
        this.press = press;
        this.vol = vol;
    }

    update_state(delta_temp: number, delta_press: number): void {
        this.temp += delta_temp;
        this.press += delta_press;
        this.vol = this.press / this.temp;
    }

    get_properties(): [number, number, number] {
        return [this.temp, this.press, this.vol];
    }
}

function simulate_state_changes(initial_state: ThermodynamicState, changes: [number, number][]): [number, number, number][] {
    let current_state = initial_state;
    let results: [number, number, number][] = [];
    for (let change of changes) {
        current_state.update_state(change[0], change[1]);
        results.push(current_state.get_properties());
    }
    return results;
}

function analyze_simulation_data(data: [number, number, number][]): [number, number, number] {
    let avg_temp = data.reduce((sum, d) => sum + d[0], 0) / data.length;
    let avg_press = data.reduce((sum, d) => sum + d[1], 0) / data.length;
    let avg_vol = data.reduce((sum, d) => sum + d[2], 0) / data.length;
    return [avg_temp, avg_press, avg_vol];
}

function main() {
    let initial_state = new ThermodynamicState(300, 1.0, 0.5);
    let changes: [number, number][] = [(10, 0.1), (-5, 0.05), (0, -0.02)];
    let simulation_data = simulate_state_changes(initial_state, changes);
    let averages = analyze_simulation_data(simulation_data);
    console.log('Average Temperature:', averages[0]);
    console.log('Average Pressure:', averages[1]);
    console.log('Average Volume:', averages[2]);
}

main();