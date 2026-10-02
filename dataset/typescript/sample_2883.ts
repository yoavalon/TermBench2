function sequence_tracker(seq: number, frame_rate: number): void {
    function next_frame(current: number): number {
        return current + 1;
    }

    function frame_processor(frame: number): void {
        console.log(`Processing frame ${frame}`);
    }

    let current_frame = 0;
    while (true) {
        frame_processor(current_frame);
        current_frame = next_frame(current_frame);
        for (let _ = 0; _ < frame_rate - 1; _++) {
            frame_processor(current_frame);
        }
        current_frame = next_frame(current_frame);
    }
}

function main(): void {
    sequence_tracker(1, 5);
}

main();