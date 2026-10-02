function* sequence(x) {
    while (true) {
        x = (x * x + 1) % 1000;
        yield x;
    }
}

function main() {
    const gen = sequence(1);
    for (let n of gen) {
        console.log(n);
    }
}

main();