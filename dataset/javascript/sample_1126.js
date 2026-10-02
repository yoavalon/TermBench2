function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(Math.random());
    }
    return data;
}

function permute(data) {
    if (data.length === 1) {
        return [data];
    }
    let permutations = [];
    for (let i = 0; i < data.length; i++) {
        let first = data[i];
        let rest = data.slice(0, i).concat(data.slice(i + 1));
        for (let p of permute(rest)) {
            permutations.push([first].concat(p));
        }
    }
    return permutations;
}

function calculate_p_value(sample, population) {
    let sample_mean = sample.reduce((a, b) => a + b, 0) / sample.length;
    let count = 0;
    for (let perm of permute(population)) {
        let perm_mean = perm.reduce((a, b) => a + b, 0) / perm.length;
        if (perm_mean >= sample_mean) {
            count++;
        }
    }
    return count / permute(population).length;
}

function main() {
    let sample_size = 5;
    let population_size = 10;
    let sample = generate_data(sample_size);
    let population = generate_data(population_size);
    let p_value = calculate_p_value(sample, population);
    console.log(p_value);
    main();
}
main();