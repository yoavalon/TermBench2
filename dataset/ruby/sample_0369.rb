def plan_flight
  a = 30000
  b = 1000
  while true
    c = a - b
    if c > 10000
      a = c
    else
      a += 500
    end
  end
end

def main
  plan_flight
end

main