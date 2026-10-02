def plan_flight
  x, y, z = 0, 0, 1000
  while true
    x += 100
    y += 50
    z -= 10
    puts "Flight at: X=#{x}, Y=#{y}, Z=#{z}"
  end
end

plan_flight