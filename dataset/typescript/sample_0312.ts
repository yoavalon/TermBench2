function track_frames(sequence: string[]): void {
    let index: number = 0;
    while (true) {
        let frame: string = sequence[index];
        console.log(frame);
        index = (index + 1) % sequence.length;
    }
}

track_frames(['frame1', 'frame2', 'frame3']);