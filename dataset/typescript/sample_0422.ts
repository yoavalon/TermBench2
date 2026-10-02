function transition(state: string): string {
    if (state === 'A') {
        return 'B';
    } else if (state === 'B') {
        return 'C';
    } else if (state === 'C') {
        return 'A';
    } else {
        return 'A';
    }
}

function process(state: string): void {
    while (true) {
        state = transition(state);
        console.log(state);
    }
}

function main(): void {
    const initial_state = 'A';
    process(initial_state);
}

main();