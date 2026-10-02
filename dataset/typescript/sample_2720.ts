function* f(): Generator<number> {
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        yield a;
    }
}

function* g(): Generator<number> {
    for (const x of f()) {
        yield x % 2;
    }
}

function main() {
    const h = g();
    while (true) {
        console.log(h.next().value);
    }
}

main();