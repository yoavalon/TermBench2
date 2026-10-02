def calculate_altitude(velocity, angle)
  g = 9.81
  altitude = velocity ** 2 * (2 * angle) / (g * 3600)
  return altitude
end

def evaluate_boundary_conditions(velocity, angle)
  if velocity < 100 or angle < 5
    return 'Conditions not met'
  else
    return 'Conditions met'
  end
end

def main
  velocity = 500
  angle = 15
  altitude = calculate_altitude(velocity, angle)
  condition_status = evaluate_boundary_conditions(velocity, angle)
  puts 'Calculated Altitude:', altitude
  puts 'Boundary Conditions:', condition_status
end

main