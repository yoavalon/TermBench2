def track_sequence
  a, b = 0.0, 1.0
  while true
    c = a + b
    a, b = b, c
    puts c
  end
end

track_sequence