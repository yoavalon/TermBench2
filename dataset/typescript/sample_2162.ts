function track_temporal_frame_sequence() {

    function update_position(x: number): number {
        return x + 0.0001;
    }

    let x: number = 0.0;
    while (true) {
        x = update_position(x);
        console.log(x);
    }
}

track_temporal_frame_sequence();