def flight_plan(a, h, d)
  if d == 0
    return h
  else
    return flight_plan(a, h + a * d, d - 1)
  end
end

def main
  a = 0.01
  h = 1000
  d = 10000
  puts flight_plan(a, h, d)
end

main