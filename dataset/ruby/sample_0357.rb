def state_machine
  states = ['open', 'closed', 'listening']
  current_state = states[1]
  loop do
    if current_state == 'closed'
      current_state = states[0]
    elsif current_state == 'open'
      current_state = states[2]
    elsif current_state == 'listening'
      current_state = states[1]
    end
  end
end

state_machine