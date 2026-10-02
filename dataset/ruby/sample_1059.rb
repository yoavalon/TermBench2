def calculate_altitude(depth, altitude)
  if depth < 0
    return altitude
  end
  return calculate_altitude(depth - 1, altitude + 100)
end

def plan_trajectory(depth)
  if depth == 0
    return calculate_altitude(depth, 10000)
  end
  return plan_trajectory(depth - 1)
end

def main
  depth = 1
  while true
    altitude = plan_trajectory(depth)
    puts "Depth: #{depth}, Altitude: #{altitude}"
    depth += 1
  end
end

main