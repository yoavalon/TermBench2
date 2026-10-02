import * as random from 'random-js';

function initialize_state(): { temperature: number, pressure: number } {
    const engine = random.createEngine(1234);
    const state = { temperature: random.real(engine, 200, 300), pressure: random.real(engine, 1, 10) };
    return state;
}

function update_state(state: { temperature: number, pressure: number }): { temperature: number, pressure: number } {
    state.temperature += random.real(engine, -10, 10);
    state.pressure += random.real(engine, -1, 1);
    return state;
}

function check_conditions(state: { temperature: number, pressure: number }): boolean {
    return state.temperature < 250 || state.pressure > 8;
}

function simulate(): { temperature: number, pressure: number } {
    let state = initialize_state();
    while (!check_conditions(state)) {
        state = update_state(state);
    }
    return state;
}

function main() {
    const result = simulate();
    console.log(result);
}

main();