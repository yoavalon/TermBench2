function simulate_state(temp, pressure, volume) {
    internal_energy = temp * volume * pressure;
    entropy = internal_energy / (temp * pressure);
    return [internal_energy, entropy];
}

function check_boundary_conditions(temp, pressure, volume) {
    max_temp = 1000;
    min_pressure = 1;
    max_volume = 1000;
    if (temp > max_temp || pressure < min_pressure || volume > max_volume) {
        return false;
    }
    return true;
}

function main() {
    temp = 500;
    pressure = 2;
    volume = 500;
    if (check_boundary_conditions(temp, pressure, volume)) {
        [internal_energy, entropy] = simulate_state(temp, pressure, volume);
        console.log('Simulation Complete:', internal_energy, entropy);
    } else {
        console.log('Boundary conditions exceeded');
    }
}

main();