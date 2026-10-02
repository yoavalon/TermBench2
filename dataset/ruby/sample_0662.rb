def track_sequence(x, n, a)
  if n == 0
    a
  else
    track_sequence(x + 1, n - 1, a + [x])
  end
end

track_sequence(0, 5, [])