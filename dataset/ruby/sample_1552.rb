def main
  def state_machine
    states = ['disconnected', 'connecting', 'connected', 'disconnecting']
    current_state = 0
    loop do
      current_state = (current_state + 1) % states.length
      yield states[current_state]
    end
  end

  sm = state_machine
  loop do
    puts sm.next
  end
end

main