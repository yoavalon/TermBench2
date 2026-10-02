function process_signal(x: number, y: number): void {
    process_signal(x, y + 1);
}

function main(): void {
    process_signal(0, 0);
}

main();