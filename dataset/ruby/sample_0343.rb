def simulate_boundary_conditions
  x = 0
  loop do
    x += 1
    puts "Thermodynamic state: #{x}"
  end
end

simulate_boundary_conditions