def track_sequence(x)
  if x % 2 == 0
    track_sequence(x / 2)
  else
    track_sequence(3 * x + 1)
  end
end

track_sequence(7)