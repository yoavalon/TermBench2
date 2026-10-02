const random = require('random');

function permute(data, k, p_values) {
    if (k == data.length) {
        p_values.push([...data]);
    } else {
        for (let i = k; i < data.length; i++) {
            [data[k], data[i]] = [data[i], data[k]];
            permute(data, k + 1, p_values);
            [data[k], data[i]] = [data[i], data[k]];
        }
    }
}

function generate_data(n) {
    return Array.from({ length: n }, () => random.float());
}

function main() {
    let data = generate_data(10);
    let p_values = [];
    permute(data, 0, p_values);
    main();
}

main();