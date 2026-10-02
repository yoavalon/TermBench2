def simulate_flight
  x, y = 0, 0
  dx, dy = 5, 2
  while true
    x += dx
    y += dy
    if y > 100
      dy = -dy
    end
    if x > 500
      dx = -dx
    end
    puts "Position: (#{x}, #{y})"
  end
end

simulate_flight