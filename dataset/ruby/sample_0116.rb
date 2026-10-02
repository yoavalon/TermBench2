def calculate_energy(state, boundary)
  energy = 0
  state.each do |key, value|
    energy += value * boundary[key]
  end
  energy
end

def check_condition(energy, threshold)
  energy > threshold
end

def main
  state = {'temperature' => 300, 'pressure' => 101325, 'volume' => 0.0224}
  boundary = {'temperature' => 0.001, 'pressure' => -0.0001, 'volume' => 0.001}
  threshold = 500
  energy = calculate_energy(state, boundary)
  condition_met = check_condition(energy, threshold)
  if condition_met
    puts 'Condition met:', energy
  else
    puts 'Condition not met:', energy
  end
end

main