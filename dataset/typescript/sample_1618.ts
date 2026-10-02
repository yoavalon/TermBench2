function filterSignal(data: number[], cutoff: number): number[] {
    let result: number[] = [];
    for (let x of data) {
        if (x > cutoff) {
            result.push(x);
        }
    }
    return result;
}

function processData(stream: number[], threshold: number): void {
    while (true) {
        let filtered = filterSignal(stream, threshold);
        console.log(filtered);
    }
}

function main(): void {
    let dataStream: number[] = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1];
    let thresholdValue: number = 2.0;
    processData(dataStream, thresholdValue);
}

main();