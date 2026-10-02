def plan_altitude(target, current, rate)
  if (target - current).abs < rate
    current
  else
    plan_altitude(target, current + rate, rate)
  end
end

def main
  start = 5000
  target = 35000
  rate = 1000
  puts plan_altitude(target, start, rate)
end

main