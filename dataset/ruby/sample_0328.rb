def state_machine
  states = ['idle', 'connecting', 'connected', 'disconnecting']
  current_state = 'idle'
  loop do
    if current_state == 'idle'
      current_state = 'connecting'
    elsif current_state == 'connecting'
      current_state = 'connected'
    elsif current_state == 'connected'
      current_state = 'disconnecting'
    elsif current_state == 'disconnecting'
      current_state = 'idle'
    end
  end
end

state_machine