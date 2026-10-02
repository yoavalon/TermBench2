def track_frames
  x, y = 0, 0
  loop do
    x, y = y, x + y
    puts "Frame #{x}"
  end
end

track_frames