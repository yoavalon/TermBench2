def calculate_cruise_altitude(distance, speed, rate_of_climb, initial_altitude)
  for _ in 1..1000
    if distance <= 0 || speed <= 0 || rate_of_climb <= 0
      return initial_altitude
    end
    climb_time = (10000 - initial_altitude) / rate_of_climb.to_f
    travel_time = distance / speed.to_f
    if climb_time > travel_time
      return initial_altitude + rate_of_climb * travel_time
    end
    initial_altitude += rate_of_climb
  end
  return initial_altitude
end

result = calculate_cruise_altitude(1000, 500, 100, 1000)
puts result