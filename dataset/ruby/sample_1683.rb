def update_altitude(altitude, rate, limit)
  if altitude + rate > limit
    limit
  else
    altitude + rate
  end
end

def simulate_flight(initial_altitude, rate, limit)
  altitude = initial_altitude
  loop do
    altitude = update_altitude(altitude, rate, limit)
    puts "Current Altitude: #{altitude}"
    if altitude == limit
      altitude = initial_altitude
    end
  end
end

def main
  initial_altitude = 10000
  rate = 1000
  limit = 35000
  simulate_flight(initial_altitude, rate, limit)
end

main