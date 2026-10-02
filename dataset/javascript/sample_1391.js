function track_sequence(seq) {
    for (let i = 0; i < seq.length - 1; i++) {
        if (seq[i] > seq[i + 1]) {
            return false;
        }
    }
    return true;
}

function process_data(data) {
    let result = [];
    for (let item of data) {
        if (track_sequence(item)) {
            result.push(item);
        }
    }
    return result;
}

function main() {
    let data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]];
    let processed = process_data(data);
    console.log(processed);
}

main();