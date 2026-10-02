def plan_altitude(desired, current, increment)
  if current >= desired
    return current
  end
  plan_altitude(desired, current + increment, increment)
end

def main
  desired_altitude = 35000
  current_altitude = 1000
  increment = 500
  result = plan_altitude(desired_altitude, current_altitude, increment)
  puts result
end

main