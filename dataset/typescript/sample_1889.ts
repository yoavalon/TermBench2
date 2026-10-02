function process_signal(data: number[], factor: number): number[] {
    const result = data.map(x => x * factor);
    return result.map(y => parseFloat(y.toFixed(5)));
}

function main() {
    const signal = [0.123456789, 0.23456789, 0.345678901];
    const factor = 1.23456;
    const processed = process_signal(signal, factor);
    console.log(processed);
}

main();