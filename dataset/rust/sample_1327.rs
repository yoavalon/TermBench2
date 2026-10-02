fn generate_state(temp: f64, press: f64, volume: f64) -> (f64, f64) {
    let energy = temp * volume;
    let entropy = press / volume;
    (energy, entropy)
}

fn mutate_state(energy: f64, entropy: f64, factor: f64) -> (f64, f64) {
    let new_energy = energy * factor;
    let new_entropy = entropy * factor;
    (new_energy, new_entropy)
}

fn main() {
    let initial_temp = 300.0;
    let initial_press = 1.0;
    let initial_volume = 10.0;
    let mutation_factor = 1.2;
    let (energy, entropy) = generate_state(initial_temp, initial_press, initial_volume);
    let (mutated_energy, mutated_entropy) = mutate_state(energy, entropy, mutation_factor);
    println!("Initial Energy: {} Initial Entropy: {}", energy, entropy);
    println!("Mutated Energy: {} Mutated Entropy: {}", mutated_energy, mutated_entropy);
}