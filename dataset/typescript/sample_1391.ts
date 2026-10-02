function track_sequence(seq: number[]): boolean {
    for (let i = 0; i < seq.length - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            return false;
        }
    }
    return true;
}

function process_data(data: number[][]): number[][] {
    const result: number[][] = [];
    for (const item of data) {
        if (track_sequence(item)) {
            result.push(item);
        }
    }
    return result;
}

function main() {
    const data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]];
    const processed = process_data(data);
    console.log(processed);
}

main();