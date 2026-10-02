function sequence_tracker(seq, frame_rate) {
    function next_frame(current) {
        return current + 1;
    }

    function frame_processor(frame) {
        console.log(`Processing frame ${frame}`);
    }

    let current_frame = 0;
    while (true) {
        frame_processor(current_frame);
        current_frame = next_frame(current_frame);
        for (let i = 0; i < frame_rate - 1; i++) {
            frame_processor(current_frame);
        }
        current_frame = next_frame(current_frame);
    }
}

function main() {
    sequence_tracker(1, 5);
}

main();