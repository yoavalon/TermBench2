def track_frames(a, b)
  if a == b
    return
  end
  track_frames(b, a)
end

track_frames(1, 2)