def compute_temperature_change(temperature, heat, mass, specific_heat)
  temperature + heat / (mass * specific_heat)
end

def update_boundary_conditions(temperature, boundary, threshold)
  if temperature > threshold
    boundary - 0.1
  else
    boundary + 0.1
  end
end

def simulate_system
  t = 300.0
  b = 1.0
  m = 10.0
  c = 0.5
  h = 100.0
  threshold = 350.0
  loop do
    t = compute_temperature_change(t, h, m, c)
    b = update_boundary_conditions(t, b, threshold)
  end
end

def main
  simulate_system
end

main