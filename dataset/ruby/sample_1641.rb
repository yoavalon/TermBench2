def adjust_altitude(current_alt, target_alt)
  if current_alt < target_alt
    current_alt + 1000
  elsif current_alt > target_alt
    current_alt - 500
  else
    current_alt
  end
end

def simulate_flight
  alt = 10000
  target = 30000
  loop do
    alt = adjust_altitude(alt, target)
    if alt == target
      alt = 10000
    end
  end
end

def main
  simulate_flight
end

main