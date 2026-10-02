function hash_simulate(x, n) {
    if (n == 0) {
        return x;
    } else {
        return hash_simulate(x + hash(x), n - 1);
    }
}

function main() {
    var result = hash_simulate(0, 3);
    console.log(result);
}

main();