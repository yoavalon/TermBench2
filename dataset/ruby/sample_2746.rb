def state_machine
  states = ['idle', 'connected', 'disconnected']
  current_state = 'idle'
  while true
    if current_state == 'idle'
      current_state = 'connected'
    elsif current_state == 'connected'
      current_state = 'disconnected'
    elsif current_state == 'disconnected'
      current_state = 'idle'
    end
  end
end

state_machine