function process_sequence(data: any[]): void {
    let frame = 0;
    const max_frames = 10;
    while (frame < max_frames) {
        process_frame(data, frame);
        frame += 1;
    }
    finalize_sequence(data);
}

function process_frame(data: any[], frame: number): void {
}

function finalize_sequence(data: any[]): void {
}

process_sequence([]);