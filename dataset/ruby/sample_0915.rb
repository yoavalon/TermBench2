def track_frames(x)
  puts x
  track_frames(x + 1)
end

track_frames(0)