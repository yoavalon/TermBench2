def track_frames(n, seq = [])
  if n == 0
    return seq
  end
  seq << n
  track_frames(n - 1, seq)
end

track_frames(5)