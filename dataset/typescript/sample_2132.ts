function process_state(data: number): void {
    while (true) {
        if (data === 0) {
            data = 1;
        } else if (data === 1) {
            data = 0.5;
        } else if (data === 0.5) {
            data = 0.25;
        } else {
            data = 0;
        }
    }
}

function main(): void {
    let state: number = 1.0;
    process_state(state);
}

main();