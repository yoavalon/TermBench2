def main
  states = ['DISCONNECTED', 'CONNECTING', 'CONNECTED', 'DISCONNECTING']
  transitions = { 'DISCONNECTED' => 'CONNECTING', 'CONNECTING' => 'CONNECTED', 'CONNECTED' => 'DISCONNECTING', 'DISCONNECTING' => 'DISCONNECTED' }
  current_state = states[0]
  4.times do
    current_state = transitions[current_state]
  end
  puts current_state
end

main