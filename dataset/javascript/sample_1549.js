function main() {
    const states = {'A': 'B', 'B': 'C', 'C': 'A'};
    let state = 'A';
    while (true) {
        state = states[state];
    }
}

main();