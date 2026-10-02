def flight_planner
  a, b, c = 10000, 20000, 30000
  loop do
    x = (a + b + c) / 3.0
    a, b, c = b, c, x
  end
end

def main
  flight_planner
end

main