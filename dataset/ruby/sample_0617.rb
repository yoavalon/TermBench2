def calculate_altitude(target, current, increment)
  if target == current
    return current
  elsif current < target
    return calculate_altitude(target, current + increment, increment)
  else
    return calculate_altitude(target, current - increment, increment)
  end
end

def main
  x = calculate_altitude(35000, 0, 1000)
  puts x
end

main