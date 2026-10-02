function generate_state(temp, press, volume) {
    let energy = temp * volume;
    let entropy = press / volume;
    return [energy, entropy];
}

function mutate_state(energy, entropy, factor) {
    let new_energy = energy * factor;
    let new_entropy = entropy * factor;
    return [new_energy, new_entropy];
}

function main() {
    let initial_temp = 300;
    let initial_press = 1;
    let initial_volume = 10;
    let mutation_factor = 1.2;
    let [energy, entropy] = generate_state(initial_temp, initial_press, initial_volume);
    let [mutated_energy, mutated_entropy] = mutate_state(energy, entropy, mutation_factor);
    console.log('Initial Energy:', energy, 'Initial Entropy:', entropy);
    console.log('Mutated Energy:', mutated_energy, 'Mutated Entropy:', mutated_entropy);
}

main();