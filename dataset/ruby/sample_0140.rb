def simulate_state(temp, pressure, volume)
  internal_energy = temp * volume * pressure
  entropy = internal_energy / (temp * pressure)
  [internal_energy, entropy]
end

def check_boundary_conditions(temp, pressure, volume)
  max_temp = 1000
  min_pressure = 1
  max_volume = 1000
  if temp > max_temp || pressure < min_pressure || volume > max_volume
    false
  else
    true
  end
end

def main
  temp = 500
  pressure = 2
  volume = 500
  if check_boundary_conditions(temp, pressure, volume)
    internal_energy, entropy = simulate_state(temp, pressure, volume)
    puts "Simulation Complete: #{internal_energy} #{entropy}"
  else
    puts "Boundary conditions exceeded"
  end
end

main()