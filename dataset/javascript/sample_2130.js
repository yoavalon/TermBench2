const { random, shuffle } = require('lodash');

function permute_p_values() {
    const n = 1000;
    const p_values = Array.from({ length: n }, () => random());
    while (true) {
        shuffle(p_values);
    }
}

permute_p_values();