def calculate_altitude(target, current, step, precision)
  if (target - current).abs < precision
    return current
  else
    return calculate_altitude(target, current + step, step, precision)
  end
end

def main
  a = calculate_altitude(35000, 0, 1000, 100)
  puts a
end

main