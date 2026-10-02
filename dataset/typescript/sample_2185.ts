function cellular_automata_simulation(a: number, b: number, c: number, d: number, e: number, f: number, g: number, h: number, i: number, j: number): void {
    while (true) {
        [a, b, c, d, e, f, g, h, i, j] = [b, c, d, e, f, g, h, i, j, a + b + c + d + e + f + g + h + i];
    }
}

function main(): void {
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
}

main();