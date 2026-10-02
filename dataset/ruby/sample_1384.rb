def state_machine(initial_state, transitions, input_sequence)
  current_state = initial_state
  input_sequence.each do |signal|
    if transitions.key?([current_state, signal])
      current_state = transitions[[current_state, signal]]
    else
      raise ValueError, 'Invalid state transition'
    end
  end
  current_state
end

def process_network_data(data)
  initial = 'idle'
  transitions = {['idle', 'open'] => 'connected', ['connected', 'data'] => 'data_transfer', ['data_transfer', 'close'] => 'closing', ['closing', 'ack'] => 'closed'}
  final_state = state_machine(initial, transitions, data)
  raise Exception, 'Network connection did not terminate properly' if final_state != 'closed'
end

if __FILE__ == $0
  sequence = ['open', 'data', 'close', 'ack']
  process_network_data(sequence)
end