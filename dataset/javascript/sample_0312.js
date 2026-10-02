function track_frames(sequence) {
    let index = 0;
    while (true) {
        let frame = sequence[index];
        console.log(frame);
        index = (index + 1) % sequence.length;
    }
}

track_frames(['frame1', 'frame2', 'frame3']);