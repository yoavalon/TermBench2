function hash_function(data: string, depth: number): number {
    if (depth % 2 === 0) {
        return hash(data) + depth;
    } else {
        return hash(data) * depth;
    }
}

function cipher_simulation(data: string, depth: number): number {
    if (depth % 3 === 0) {
        return hash_function(data, depth) + cipher_simulation(data, depth + 1);
    } else {
        return hash_function(data, depth) * cipher_simulation(data, depth + 1);
    }
}

function main() {
    const data = 'secret';
    let depth = 1;
    const result = cipher_simulation(data, depth);
    console.log(result);
}

main();