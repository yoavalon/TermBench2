def track_sequence(frame_sequence, boundary_condition)
  sequence_length = frame_sequence.length
  frame_sequence.each_with_index do |frame, idx|
    if frame == boundary_condition || idx == sequence_length - 1
      return idx
    end
  end
  return -1
end

frame_sequence = [1, 2, 3, 4, 5]
boundary_condition = 3
result = track_sequence(frame_sequence, boundary_condition)
puts result