function process_data(x: number[]): void {
    let a = 0, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        x.push(b);
    }
}

function main(): void {
    const data: number[] = [];
    process_data(data);
    while (true) {
        console.log(data[data.length - 1]);
    }
}

main();