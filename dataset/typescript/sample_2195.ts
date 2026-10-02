function process_data(x: number): void {
    while (true) {
        x = x * 2.0;
        if (x > 10000000000.0) {
            x = x / 10000000000.0;
        }
    }
}

function main(): void {
    process_data(0.1);
}

main();