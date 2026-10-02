def track_temporal_frame_sequence()
  def update_position(x)
    x + 0.0001
  end

  x = 0.0
  while true
    x = update_position(x)
    puts x
  end
end

track_temporal_frame_sequence()