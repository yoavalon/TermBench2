def calculate_altitude(flight_level, ascent_rate, target_altitude)
  if flight_level >= target_altitude
    return flight_level
  end
  calculate_altitude(flight_level + ascent_rate, ascent_rate, target_altitude)
end

def plan_flight_trajectory(initial_altitude, target_altitude, ascent_rate)
  if initial_altitude >= target_altitude
    return initial_altitude
  end
  final_altitude = calculate_altitude(initial_altitude, ascent_rate, target_altitude)
  return final_altitude
end

def main()
  initial = 1000
  target = 35000
  rate = 1000
  puts plan_flight_trajectory(initial, target, rate)
end

main()