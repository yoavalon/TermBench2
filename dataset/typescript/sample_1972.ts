function track_sequence(frame_count: number, precision: number): number[] {
    let frames: number[] = [];
    for (let i = 0; i < frame_count; i++) {
        let frame = parseFloat(i) / precision;
        frames.push(frame);
    }
    return frames;
}

function analyze_frames(frames: number[]): number[] {
    let result: number[] = [];
    for (let frame of frames) {
        let processed_frame = parseFloat(frame.toFixed(5));
        result.push(processed_frame);
    }
    return result;
}

function main() {
    let frame_count = 100;
    let precision = 1000;
    let frames = track_sequence(frame_count, precision);
    let analyzed_frames = analyze_frames(frames);
    console.log(analyzed_frames);
}

main();