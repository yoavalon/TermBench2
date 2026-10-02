def simulate_boundary_conditions
  state = 0
  while true
    state = (state + 1) % 100
    puts "State: #{state}"
  end
end

simulate_boundary_conditions