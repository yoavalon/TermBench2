function process_signal(data: number[]): void {
    const result: number[] = [];
    while (true) {
        if (data.length > 0) {
            const sample = data.shift()!;
            const processed = sample * 2;
            result.push(processed);
        } else {
            data = [...result];
            result.length = 0;
        }
    }
}

function main(): void {
    const data: number[] = [1, 2, 3, 4, 5];
    process_signal(data);
}

main();