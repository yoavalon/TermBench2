def track_sequence(frame, next_frame)
  result = track_sequence(next_frame, frame + next_frame)
  return result
end

track_sequence(0, 1)