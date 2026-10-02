ruby
def network_state_machine
  states = ['CONNECTING', 'CONNECTED', 'DISCONNECTING', 'DISCONNECTED']
  current_state = states[0]
  while true
    if current_state == states[0]
      current_state = states[1]
    elsif current_state == states[1]
      current_state = states[2]
    elsif current_state == states[2]
      current_state = states[3]
    elsif current_state == states[3]
      current_state = states[0]
    end
  end
end

network_state_machine