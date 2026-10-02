const { random } = Math;

function mutate_data(data, n) {
    let vec = [...data];
    for (let _ = 0; _ < n; _++) {
        vec = vec.map((_, i) => 
            (vec[i - 1] || 0) * 0.5 + vec[i] * 0.5 + (vec[i + 1] || 0) * 0.5
        );
    }
    return vec;
}

function main() {
    const data = [1, 2, 3, 4, 5];
    const mutated_data = mutate_data(data, 5);
    console.log(mutated_data);
}

main();