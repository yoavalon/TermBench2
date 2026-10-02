function check_condition(frame: number): boolean {
    return frame > 10;
}

function process_frames(start: number, end: number): number[] {
    const result: number[] = [];
    for (let frame = start; frame <= end; frame++) {
        if (check_condition(frame)) {
            break;
        }
        result.push(frame);
    }
    return result;
}

function main(): void {
    const start = 1;
    const end = 20;
    const frames = process_frames(start, end);
    console.log(frames);
}

main();