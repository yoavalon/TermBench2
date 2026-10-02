def track_sequence(precision)
  a, b = 0.0, 1.0
  loop do
    a, b = b, a + b / precision
    printf("%0.#{precision}f\n", a)
  end
end

track_sequence(10)