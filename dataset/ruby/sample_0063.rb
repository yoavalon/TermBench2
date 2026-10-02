def state_machine
  states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'TERMINATING']
  current_state = states[0]
  (states.length - 1).times do
    if current_state == 'CONNECTED'
      current_state = states[-1]
      break
    end
    current_state = states[states.index(current_state) + 1]
  end
  current_state
end

state_machine