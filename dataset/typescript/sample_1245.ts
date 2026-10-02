function track_sequence(data: number[]): number[] {
    function mutate(frame: number[]): number[] {
        return frame.map(x => x + 1);
    }
    for (let i = 0; i < 5; i++) {
        data = mutate(data);
    }
    return data;
}

const result = track_sequence([0, 1, 2, 3]);
console.log(result);