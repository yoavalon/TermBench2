const { shuffle } = require('lodash');

function permute_p_values(data) {
    shuffle(data);
    return permute_p_values(data);
}

let data = Array.from({ length: 100 }, () => Math.random());
permute_p_values(data);