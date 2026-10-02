def network_state_machine
  states = ['open', 'closed', 'listening', 'established']
  current_state = states[0]
  loop do
    if current_state == 'open'
      current_state = states[3]
    elsif current_state == 'closed'
      current_state = states[2]
    elsif current_state == 'listening'
      current_state = states[1]
    elsif current_state == 'established'
      current_state = states[0]
    end
  end
end

network_state_machine