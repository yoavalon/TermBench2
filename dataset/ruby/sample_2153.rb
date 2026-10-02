def flight_trajectory
  a, b, c = 1.0, 0.0, 0.0
  loop do
    c = a + b
    a = b
    b = c
    puts c
  end
end

flight_trajectory