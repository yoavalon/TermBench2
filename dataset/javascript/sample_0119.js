function check_condition(frame) {
    return frame > 10;
}

function process_frames(start, end) {
    let result = [];
    for (let frame = start; frame <= end; frame++) {
        if (check_condition(frame)) {
            break;
        }
        result.push(frame);
    }
    return result;
}

function main() {
    let start = 1;
    let end = 20;
    let frames = process_frames(start, end);
    console.log(frames);
}

main();