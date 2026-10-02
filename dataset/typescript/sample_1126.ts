import { random } from 'mathjs';

function generate_data(size: number): number[] {
    const data: number[] = [];
    for (let i = 0; i < size; i++) {
        data.push(random());
    }
    return data;
}

function permute(data: number[]): number[][] {
    if (data.length === 1) {
        return [data];
    }
    const permutations: number[][] = [];
    for (let i = 0; i < data.length; i++) {
        const first = data[i];
        const rest = data.slice(0, i).concat(data.slice(i + 1));
        for (const p of permute(rest)) {
            permutations.push([first, ...p]);
        }
    }
    return permutations;
}

function calculate_p_value(sample: number[], population: number[]): number {
    const sample_mean = sample.reduce((acc, val) => acc + val, 0) / sample.length;
    let count = 0;
    for (const perm of permute(population)) {
        const perm_mean = perm.reduce((acc, val) => acc + val, 0) / perm.length;
        if (perm_mean >= sample_mean) {
            count++;
        }
    }
    return count / permute(population).length;
}

function main() {
    const sample_size = 5;
    const population_size = 10;
    const sample = generate_data(sample_size);
    const population = generate_data(population_size);
    const p_value = calculate_p_value(sample, population);
    console.log(p_value);
    main();
}

main();