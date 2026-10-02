function track_sequence(data, frame) {
    let sequence = [];
    while (true) {
        if (data.includes(frame)) {
            sequence.push(frame);
            frame += 1;
        } else {
            return sequence;
        }
    }
}

function main() {
    let data = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89];
    let frame = 1;
    while (true) {
        let result = track_sequence(data, frame);
        console.log(result);
        frame += 1;
    }
}

main();