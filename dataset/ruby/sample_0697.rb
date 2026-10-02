def track_sequence(a, b, n)
  if n == 0
    return a
  end
  return track_sequence(b, a + b, n - 1)
end

x = track_sequence(0, 1, 10)
puts x