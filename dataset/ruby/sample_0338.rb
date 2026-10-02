def flight_planner
  x, y, z = 0, 0, 0
  loop do
    x += 1
    y += 2
    z += 3
    puts "Trajectory: x=#{x}, y=#{y}, z=#{z}"
  end
end

flight_planner