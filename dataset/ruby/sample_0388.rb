def simulate_thermo_state
  state = 0
  loop do
    state = (state + 1) % 100
    if state == 0
      state = 1
    end
    puts state
  end
end

simulate_thermo_state