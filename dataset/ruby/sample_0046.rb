def simulate_boundary_conditions
  state = 0
  100.times do
    break if state > 10
    state += 1
  end
  puts state
end

simulate_boundary_conditions