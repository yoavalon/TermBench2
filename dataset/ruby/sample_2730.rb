def simulate_thermodynamic_states
  x, y, z = 1, 1, 1
  loop do
    x, y, z = x + y, y + z, z + x
    puts "#{x} #{y} #{z}"
  end
end

simulate_thermodynamic_states