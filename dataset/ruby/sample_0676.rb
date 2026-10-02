def plan_altitude(target, current, step)
  if (target - current).abs <= step
    return current
  elsif target > current
    return plan_altitude(target, current + step, step)
  else
    return plan_altitude(target, current - step, step)
  end
end

def main()
  puts plan_altitude(35000, 10000, 5000)
end

main()