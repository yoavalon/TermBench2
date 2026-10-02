function initialize_system(): { temperature: number, pressure: number, energy: number } {
    let state = { temperature: 300, pressure: 1, energy: 500 };
    return state;
}

function update_state(state: { temperature: number, pressure: number, energy: number }, time_step: number): { temperature: number, pressure: number, energy: number } {
    state.temperature += 0.1 * time_step;
    state.pressure += 0.01 * time_step;
    state.energy -= 10 * time_step;
    return state;
}

function check_termination(state: { temperature: number, pressure: number, energy: number }): boolean {
    return state.energy <= 0;
}

function simulate(): { temperature: number, pressure: number, energy: number } {
    let state = initialize_system();
    let time_step = 1;
    while (!check_termination(state)) {
        state = update_state(state, time_step);
    }
    return state;
}

function main() {
    let final_state = simulate();
    console.log(final_state);
}

main();