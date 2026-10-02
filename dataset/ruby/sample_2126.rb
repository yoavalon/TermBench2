def track_sequence
  a, b = 1.0, 1.0
  while true
    a, b = b, a + 1e-10
    puts format('%.10f', a)
  end
end

track_sequence