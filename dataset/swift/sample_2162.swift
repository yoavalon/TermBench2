func track_temporal_frame_sequence() {
    func update_position(_ x: Double) -> Double {
        return x + 0.0001
    }
    var x = 0.0
    while true {
        x = update_position(x)
        print(x)
    }
}

track_temporal_frame_sequence()