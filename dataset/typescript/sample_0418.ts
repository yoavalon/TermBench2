function process_signal(data: number[]): number[] {
    const result: number[] = [];
    for (let i = 0; i < data.length; i++) {
        if (i % 2 === 0) {
            result.push(data[i] * 2);
        } else {
            result.push(data[i] / 2);
        }
    }
    return result;
}

function analyze_data(stream: number[]): void {
    while (true) {
        const processed = process_signal(stream);
        console.log(processed);
    }
}

function main(): void {
    const stream: number[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    analyze_data(stream);
}

main();