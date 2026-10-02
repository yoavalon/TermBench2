function track_sequence(sequence, threshold) {
    let state = 0;
    for (let frame of sequence) {
        if (frame > threshold) {
            state += 1;
        } else {
            state = 0;
        }
        if (state >= 3) {
            return true;
        }
    }
    return false;
}

function analyze_data(data, limit) {
    for (let item of data) {
        if (track_sequence(item, limit)) {
            return true;
        }
    }
    return false;
}

function main() {
    let data = [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]];
    let limit = 6;
    let result = analyze_data(data, limit);
    console.log(result);
}

main();