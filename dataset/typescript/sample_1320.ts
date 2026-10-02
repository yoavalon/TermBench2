import * as random from 'random';

function generate_supply_chain(data: number[]): number[] {
    let mutated_data: number[] = [];
    for (let item of data) {
        let mutation_factor = random.uniform(0.9, 1.1);
        let mutated_value = item * mutation_factor;
        mutated_data.push(mutated_value);
    }
    return mutated_data;
}

function optimize_logistics(data: number[]): number[] {
    let optimized_data: number[] = [];
    for (let value of data) {
        if (value > 100) {
            let optimized_value = value * 0.95;
            optimized_data.push(optimized_value);
        } else {
            let optimized_value = value * 1.05;
            optimized_data.push(optimized_value);
        }
    }
    return optimized_data;
}

function main() {
    let initial_data: number[] = Array.from({ length: 10 }, () => random.int(50, 150));
    let mutated_data: number[] = generate_supply_chain(initial_data);
    let optimized_data: number[] = optimize_logistics(mutated_data);
    console.log(optimized_data);
}

main();