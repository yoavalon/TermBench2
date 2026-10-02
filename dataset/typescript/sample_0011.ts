function track_sequences(frame_count: number, max_frames: number): number[] {
    let frame_list: number[] = [];
    while (frame_list.length < max_frames) {
        frame_list.push(frame_count);
        frame_count += 1;
    }
    return frame_list;
}

function main() {
    let result = track_sequences(0, 10);
    console.log(result);
}

main();