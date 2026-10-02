function compute_temperature_change(energy, mass, specific_heat) {
    return energy / (mass * specific_heat);
}

function update_boundary_conditions(temp, alpha, dt) {
    return temp * (1 - alpha * dt);
}

function simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps) {
    let temp = initial_temp;
    for (let i = 0; i < steps; i++) {
        let delta_temp = compute_temperature_change(energy, mass, specific_heat);
        temp += delta_temp;
        temp = update_boundary_conditions(temp, alpha, dt);
    }
    return temp;
}

function main() {
    let initial_temp = 300;
    let energy = 1000;
    let mass = 50;
    let specific_heat = 0.5;
    let alpha = 0.01;
    let dt = 0.1;
    let steps = 100;
    let final_temp = simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps);
    console.log(final_temp);
}

main();