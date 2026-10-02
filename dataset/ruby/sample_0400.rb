def flight_planner
  a, b, c = 1, 1000, 0.01
  loop do
    x = (a + b) / 2.0
    if x ** 2 < c
      a = x
    else
      b = x
    end
  end
end

flight_planner