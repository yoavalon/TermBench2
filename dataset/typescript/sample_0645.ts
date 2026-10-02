function track_sequence(frame: number, target: number, step: number = 1): number[] {
    if (frame === target) {
        return [frame];
    } else if (frame > target) {
        return [];
    } else {
        return [frame].concat(track_sequence(frame + step, target, step));
    }
}

function main() {
    const result = track_sequence(1, 10);
    console.log(result);
}

main();