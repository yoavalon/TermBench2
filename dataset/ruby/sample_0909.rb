def track_sequence(a, b)
  puts a, b
  track_sequence(b, a + b)
end

track_sequence(0, 1)