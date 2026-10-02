function simulate_state(temp: number, pressure: number, volume: number): [number, number] {
    let internal_energy = temp * volume * pressure;
    let entropy = internal_energy / (temp * pressure);
    return [internal_energy, entropy];
}

function check_boundary_conditions(temp: number, pressure: number, volume: number): boolean {
    let max_temp = 1000;
    let min_pressure = 1;
    let max_volume = 1000;
    if (temp > max_temp || pressure < min_pressure || volume > max_volume) {
        return false;
    }
    return true;
}

function main() {
    let temp = 500;
    let pressure = 2;
    let volume = 500;
    if (check_boundary_conditions(temp, pressure, volume)) {
        let [internal_energy, entropy] = simulate_state(temp, pressure, volume);
        console.log('Simulation Complete:', internal_energy, entropy);
    } else {
        console.log('Boundary conditions exceeded');
    }
}

main();