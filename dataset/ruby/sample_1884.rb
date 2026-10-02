def track_sequence
  a, b = 0.0, 1.0
  1000.times do
    a, b = b, a + b
    return a if b == a
  end
end

track_sequence