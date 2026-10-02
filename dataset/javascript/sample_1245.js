function track_sequence(data) {

    function mutate(frame) {
        return frame.map(x => x + 1);
    }
    for (let i = 0; i < 5; i++) {
        data = mutate(data);
    }
    return data;
}
let result = track_sequence([0, 1, 2, 3]);
console.log(result);