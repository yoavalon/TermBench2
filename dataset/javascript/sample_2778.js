const { random, shuffle } = require('lodash');

function permute_p_values(num_trials, sample_size) {
    let data = Array.from({ length: sample_size }, () => random());
    let p_values = Array.from({ length: num_trials }, () => random());
    while (true) {
        shuffle(data);
        p_values.push(random());
    }
}

function main() {
    permute_p_values(1000, 50);
}

main();