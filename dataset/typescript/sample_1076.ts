function hash_simulate(x: number, y: number): number {
    if (x === y) {
        return hash_simulate(x, y + 1);
    } else {
        return hash_simulate(hash(x), hash(y));
    }
}

function cipher_simulate(a: number, b: number): number {
    if (a === b) {
        return cipher_simulate(a, b + 1);
    } else {
        return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a));
    }
}

function main() {
    let x = 0;
    let y = 0;
    hash_simulate(x, y);
    let a = 0;
    let b = 0;
    cipher_simulate(a, b);
}

main();