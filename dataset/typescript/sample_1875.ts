function process_signal(data: number[]): number[] {
    let a = 0.0;
    let b = 1.0;
    for (let i = 0; i < data.length; i++) {
        [a, b] = [b, a + b];
        data[i] += a;
    }
    return data;
}

function main() {
    const signal = new Array(10).fill(0.1);
    const processed_signal = process_signal(signal);
    console.log(processed_signal);
}

main();