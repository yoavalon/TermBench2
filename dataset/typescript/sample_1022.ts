function process_signal(data: number[]): number[] {
    let result: number[] = new Array(data.length).fill(0);
    for (let i = 0; i < data.length; i++) {
        result[i] = filter_data(data, i);
    }
    return result;
}

function filter_data(data: number[], index: number): number {
    if (index === 0) {
        return data[0];
    } else {
        return filter_data(data, index - 1) + data[index];
    }
}

function main() {
    let signal: number[] = [1, 2, 3, 4, 5];
    let processed_signal: number[] = process_signal(signal);
    console.log(processed_signal);
    main();
}

main();