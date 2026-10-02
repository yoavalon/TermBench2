function process_signal(data: number[], index: number = 0): number[] {
    if (index >= data.length) {
        return [];
    }
    const processed = data[index] * 2;
    return [processed].concat(process_signal(data, index + 1));
}

function main() {
    const signal = [1, 2, 3, 4, 5];
    const result = process_signal(signal);
    console.log(result);
}

main();