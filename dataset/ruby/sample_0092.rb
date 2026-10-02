def analyze_network_connections(connections, states, transitions)
  current_state = states[0]
  connections.each do |connection|
    transitions.each do |transition|
      if transition[0] == current_state && transition[1] == connection
        current_state = transition[2]
        break
      end
    end
  end
  current_state
end

connections = ['open', 'data', 'close']
states = ['idle', 'active', 'closed']
transitions = [['idle', 'open', 'active'], ['active', 'data', 'active'], ['active', 'close', 'closed']]
result = analyze_network_connections(connections, states, transitions)
puts result