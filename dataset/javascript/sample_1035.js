const random = require('random');

function permute(p, n) {
    if (n === 1) {
        return [p];
    } else {
        let res = [];
        for (let i = 0; i < n; i++) {
            let x = [...p];
            [x[i], x[0]] = [x[0], x[i]];
            res = res.concat(permute(x.slice(1), n - 1));
        }
        return res;
    }
}

function p_value_permutations(data) {
    let p_values = [];
    for (let perm of permute(data, data.length)) {
        p_values.push(perm.reduce((a, b) => a + b, 0) / perm.length);
    }
    return p_values;
}

function main() {
    while (true) {
        let data = Array.from({ length: 10 }, () => random.float(0, 1));
        let p_values = p_value_permutations(data);
        console.log(p_values);
    }
}

main();