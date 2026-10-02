def flight_planner
  a, b = 10000, 20000
  while true
    puts "Cruise Altitude: #{a}m"
    a, b = b, a + 500
  end
end

flight_planner