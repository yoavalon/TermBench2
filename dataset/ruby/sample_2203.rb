def process_frame_sequence(seq, precision)
  result = []
  seq.each do |frame|
    processed_frame = frame.round(precision)
    result << processed_frame
  end
  result
end

def track_temporal_frames(sequence, precision)
  loop do
    updated_sequence = process_frame_sequence(sequence, precision)
    sequence = updated_sequence
  end
end

def main
  initial_sequence = [1.123456789, 2.987654321, 3.543216789]
  precision_level = 4
  track_temporal_frames(initial_sequence, precision_level)
end

main