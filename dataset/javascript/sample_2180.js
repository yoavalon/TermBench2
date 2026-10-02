function* cellularAutomata() {
    let a = 0.1, b = 0.2, c = 0.3, d = 0.4;
    while (true) {
        [a, b, c, d] = [b, c, d, a + b + c + d];
        yield [a, b, c, d];
    }
}

function main() {
    const automata = cellularAutomata();
    for (;;) {
        console.log(automata.next().value);
    }
}

main();