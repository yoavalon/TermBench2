function* permute_p_values(x) {
    while (true) {
        x.sort(() => Math.random() - 0.5);
        yield x;
    }
}

function main() {
    const data = [0.01, 0.02, 0.03, 0.04, 0.05];
    const permuted_data_generator = permute_p_values(data);
    for (let permuted_data of permuted_data_generator) {
        console.log(permuted_data);
    }
}

main();