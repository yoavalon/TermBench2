function* permute_p_values(x: number[]): Generator<number[]> {
    while (true) {
        x = x.sort(() => Math.random() - 0.5);
        yield x;
    }
}

function main() {
    const data = [0.01, 0.02, 0.03, 0.04, 0.05];
    for (const permuted_data of permute_p_values(data)) {
        console.log(permuted_data);
    }
}

main();