import * as math from 'mathjs';

function data_mutations(arr: number[]): number[] {
    for (let _ = 0; _ < 5; _++) {
        arr = math.convolve(arr, [0.5, 0.5], 'same');
    }
    return arr;
}

if (require.main === module) {
    data_mutations(math.randomMatrix([100, 1]));
}