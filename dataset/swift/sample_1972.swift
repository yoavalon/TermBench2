func track_sequence(frame_count: Int, precision: Int) -> [Double] {
    var frames: [Double] = []
    for i in 0..<frame_count {
        let frame = Double(i) / Double(precision)
        frames.append(frame)
    }
    return frames
}

func analyze_frames(frames: [Double]) -> [Double] {
    var result: [Double] = []
    for frame in frames {
        let processed_frame = round(frame * 100000) / 100000
        result.append(processed_frame)
    }
    return result
}

func main() {
    let frame_count = 100
    let precision = 1000
    let frames = track_sequence(frame_count: frame_count, precision: precision)
    let analyzed_frames = analyze_frames(frames: frames)
    print(analyzed_frames)
}

main()