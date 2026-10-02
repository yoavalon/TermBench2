def simulate_boundary_conditions
  while true
    state = [1, 2, 3, 4, 5]
    (0...state.length).each do |i|
      state[i] += 0.1
    end
    puts state.inspect
  end
end

simulate_boundary_conditions