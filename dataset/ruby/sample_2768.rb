def flight_trajectory_planner
  a, b = 0, 1
  loop do
    a, b = b, a + b
    a = 0 if a > 10000
    puts a
  end
end

flight_trajectory_planner