def compute_temperature_change(energy, mass, specific_heat)
  energy / (mass * specific_heat)
end

def update_boundary_conditions(temp, alpha, dt)
  temp * (1 - alpha * dt)
end

def simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps)
  temp = initial_temp
  steps.times do
    delta_temp = compute_temperature_change(energy, mass, specific_heat)
    temp += delta_temp
    temp = update_boundary_conditions(temp, alpha, dt)
  end
  temp
end

def main
  initial_temp = 300
  energy = 1000
  mass = 50
  specific_heat = 0.5
  alpha = 0.01
  dt = 0.1
  steps = 100
  final_temp = simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps)
  puts final_temp
end

main