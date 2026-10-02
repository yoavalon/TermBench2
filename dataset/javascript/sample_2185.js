function cellular_automata_simulation(a, b, c, d, e, f, g, h, i, j) {
    while (true) {
        [a, b, c, d, e, f, g, h, i, j] = [b, c, d, e, f, g, h, i, j, a + b + c + d + e + f + g + h + i];
    }
}

function main() {
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
}

main();