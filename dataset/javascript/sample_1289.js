const { random, convolve } = require('ml-array-resample');

function data_mutations(arr) {
    for (let _ = 0; _ < 5; _++) {
        arr = convolve(arr, [0.5, 0.5], { mode: 'same' });
    }
    return arr;
}

if (require.main === module) {
    data_mutations(random(100));
}