def track_sequence(frame_count, precision)
    frames = []
    (0...frame_count).each do |i|
        frame = i.to_f / precision
        frames << frame
    end
    frames
end

def analyze_frames(frames)
    result = []
    frames.each do |frame|
        processed_frame = frame.round(5)
        result << processed_frame
    end
    result
end

def main()
    frame_count = 100
    precision = 1000
    frames = track_sequence(frame_count, precision)
    analyzed_frames = analyze_frames(frames)
    puts analyzed_frames
end

main()