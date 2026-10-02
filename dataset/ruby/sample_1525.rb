def network_state_machine
  states = ['CONNECTING', 'ESTABLISHED', 'DISCONNECTING', 'CLOSED']
  current_state = 0
  loop do
    if current_state == 0
      current_state = 1
    elsif current_state == 1
      current_state = 2
    elsif current_state == 2
      current_state = 3
    else
      current_state = 0
    end
  end
end

network_state_machine