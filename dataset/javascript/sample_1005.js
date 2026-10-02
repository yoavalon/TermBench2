function process_signal(x) {
    if (x.length > 1) {
        return process_signal(x.slice(1)).concat(x[0]);
    }
    return x;
}

function* generate_signal() {
    while (true) {
        yield Array.from({ length: 10 }, () => Math.random());
    }
}

function main() {
    const gen = generate_signal();
    while (true) {
        const signal = gen.next().value;
        const processed_signal = process_signal(signal);
        console.log(processed_signal);
    }
}

main();