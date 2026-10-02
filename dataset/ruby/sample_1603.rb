def update_altitude(current_alt, target_alt, rate)
  if current_alt < target_alt
    [current_alt + rate, target_alt].min
  elsif current_alt > target_alt
    [current_alt - rate, target_alt].max
  else
    current_alt
  end
end

def simulate_flight
  current_alt = 0
  target_alt = 35000
  rate = 500
  loop do
    current_alt = update_altitude(current_alt, target_alt, rate)
    if current_alt == target_alt
      target_alt = 0
      rate = 100
    else
      rate = 500
    end
  end
end

simulate_flight