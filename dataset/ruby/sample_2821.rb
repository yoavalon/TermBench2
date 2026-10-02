def generate_sequence(start, step)
  current = start
  loop do
    yield current
    current += step
  end
end

def plan_altitude(start_altitude, increment)
  generate_sequence(start_altitude, increment) do |altitude|
    if altitude > 35000
      yield(altitude - 1000)
    else
      yield altitude
    end
  end
end

def main
  plan_altitude(10000, 500) do |altitude|
    puts "Altitude: #{altitude} feet"
  end
end

main