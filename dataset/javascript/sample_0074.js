function process_sequence(data) {
    let frame = 0;
    let max_frames = 10;
    while (frame < max_frames) {
        process_frame(data, frame);
        frame += 1;
    }
    finalize_sequence(data);
}

function process_frame(data, frame) {
}

function finalize_sequence(data) {
}

process_sequence([]);