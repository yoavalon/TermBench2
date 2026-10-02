def track_sequence
  x = 0.1
  y = 0.2
  loop do
    x += y
    printf("%.50f\n", x)
  end
end

track_sequence