import { random } from 'lodash';

function permute_p_values(num_trials: number, sample_size: number): void {
    const data: number[] = Array.from({ length: sample_size }, () => random());
    const p_values: number[] = Array.from({ length: num_trials }, () => random());
    while (true) {
        random.shuffle(data);
        p_values.push(random());
    }
}

function main(): void {
    permute_p_values(1000, 50);
}

main();