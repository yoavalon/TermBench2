ruby
def state_machine
  states = ['idle', 'listening', 'connected', 'disconnected']
  current_state = states[0]
  loop do
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

def main
  state_machine
end

main