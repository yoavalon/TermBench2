def simulate_pressure(a, b, c)
  (a + b + c) / 3.0
end

def calculate_temperature(pressure, constant)
  pressure * constant
end

def analyze_system(a, b, c, constant)
  pressure = simulate_pressure(a, b, c)
  temperature = calculate_temperature(pressure, constant)
  temperature
end

def main
  a = 100.0
  b = 200.0
  c = 150.0
  constant = 0.5
  result = analyze_system(a, b, c, constant)
  puts result
end

main