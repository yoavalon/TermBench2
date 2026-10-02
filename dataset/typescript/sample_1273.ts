function sequence_tracker(frame_count: number, max_frames: number): number[] {
    let frame_list: number[] = [];
    for (let i = 0; i < frame_count; i++) {
        frame_list.push(i);
        if (frame_list.length >= max_frames) {
            break;
        }
    }
    return frame_list;
}

if (require.main === module) {
    let result = sequence_tracker(10, 5);
    console.log(result);
}