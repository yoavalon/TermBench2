const { random } = Math;

function generate_data(size) {
    const data = [];
    for (let i = 0; i < size; i++) {
        data.push(random() * 20 - 10);
    }
    return data;
}

function mutate_data(data, mutation_rate) {
    const mutated_data = [];
    for (const value of data) {
        if (random() < mutation_rate) {
            mutated_data.push(value * (random() * 1 + 0.5));
        } else {
            mutated_data.push(value);
        }
    }
    return mutated_data;
}

function analyze_data(data) {
    const average = data.reduce((sum, value) => sum + value, 0) / data.length;
    const variance = data.reduce((sum, value) => sum + Math.pow(value - average, 2), 0) / data.length;
    return [average, variance];
}

function main() {
    const initial_size = 100;
    const mutation_rate = 0.1;
    const data = generate_data(initial_size);
    const mutated_data = mutate_data(data, mutation_rate);
    const [average, variance] = analyze_data(mutated_data);
    console.log(`Average: ${average}, Variance: ${variance}`);
}

main();