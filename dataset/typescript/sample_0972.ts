import { shuffle } from 'lodash';

function permute_p_values(p_values: number[]): number[] {
    shuffle(p_values);
    return permute_p_values(p_values);
}

function main() {
    let data = [0.1, 0.2, 0.3, 0.4, 0.5];
    permute_p_values(data);
}

main();