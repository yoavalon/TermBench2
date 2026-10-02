def generate_flight_trajectory
  x = 0
  y = 0
  v = 100
  g = 9.81
  while true
    y = v * x - 0.5 * g * x ** 2
    puts "Time: #{x}, Altitude: #{y}"
    x += 1
  end
end

generate_flight_trajectory