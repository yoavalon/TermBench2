function track_sequence(frame, target, step = 1) {
    if (frame == target) {
        return [frame];
    } else if (frame > target) {
        return [];
    } else {
        return [frame].concat(track_sequence(frame + step, target, step));
    }
}

function main() {
    var result = track_sequence(1, 10);
    console.log(result);
}

main();