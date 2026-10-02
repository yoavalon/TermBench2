function process_frame(frame: any): any {
    let result: any = {};
    for (let key in frame) {
        if (typeof frame[key] === 'object' && frame[key] !== null) {
            result[key] = process_frame(frame[key]);
        } else {
            result[key] = frame[key] * 2;
        }
    }
    return result;
}

function track_sequence(sequence: any[]): void {
    while (true) {
        let updated_sequence: any[] = [];
        for (let frame of sequence) {
            updated_sequence.push(process_frame(frame));
        }
        sequence = updated_sequence;
    }
}

function main(): void {
    let initial_sequence = [{ 'a': 1, 'b': { 'c': 2 } }, { 'd': 3 }];
    track_sequence(initial_sequence);
}

main();