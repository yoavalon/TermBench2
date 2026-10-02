function calculate_energy(state: { [key: string]: number }, boundary: { [key: string]: number }): number {
    let energy = 0;
    for (let key in state) {
        energy += state[key] * boundary[key];
    }
    return energy;
}

function check_condition(energy: number, threshold: number): boolean {
    if (energy > threshold) {
        return true;
    }
    return false;
}

function main() {
    let state = { 'temperature': 300, 'pressure': 101325, 'volume': 0.0224 };
    let boundary = { 'temperature': 0.001, 'pressure': -0.0001, 'volume': 0.001 };
    let threshold = 500;
    let energy = calculate_energy(state, boundary);
    let condition_met = check_condition(energy, threshold);
    if (condition_met) {
        console.log('Condition met:', energy);
    } else {
        console.log('Condition not met:', energy);
    }
}

main();