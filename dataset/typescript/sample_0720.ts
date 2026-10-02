function recursive_filter(data: number[], index: number, factor: number): number {
    if (index == 0) {
        return data[0];
    }
    return factor * data[index] + (1 - factor) * recursive_filter(data, index - 1, factor);
}

function process_signal(data: number[], factor: number): number[] {
    const processed: number[] = [];
    for (let i = 0; i < data.length; i++) {
        processed.push(recursive_filter(data, i, factor));
    }
    return processed;
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const factor = 0.5;
    const result = process_signal(signal, factor);
    console.log(result);
}

main();