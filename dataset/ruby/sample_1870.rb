def state_machine_network_connection
  state = 0
  while state < 3
    if state == 0
      state += 1
    elsif state == 1
      state += 1
    elsif state == 2
      state += 1
    end
  end
  return state
end

state_machine_network_connection