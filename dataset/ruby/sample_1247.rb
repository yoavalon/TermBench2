def track_sequence_frames
  x, y = 0, 1
  while x < 100
    x, y = y, x + y
  end
  x
end

track_sequence_frames