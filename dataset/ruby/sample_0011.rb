def track_sequences(frame_count, max_frames)
    frame_list = []
    while frame_list.length < max_frames
        frame_list << frame_count
        frame_count += 1
    end
    return frame_list
end

def main()
    result = track_sequences(0, 10)
    puts result
end

main()