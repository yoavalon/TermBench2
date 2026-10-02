import * as np from 'numpy';

function mutate_data(data: number[], n: number): number[] {
    let vec = np.array(data);
    for (let i = 0; i < n; i++) {
        vec = np.convolve(vec, np.random.rand(3), 'same');
    }
    return vec.tolist();
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let mutated_data = mutate_data(data, 5);
    console.log(mutated_data);
}

main();