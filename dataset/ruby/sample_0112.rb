def process_state(state, data)
  if state == 'start'
    ['connect', data]
  elsif state == 'connect'
    if data == 'success'
      ['data_transfer', data]
    else
      ['error', data]
    end
  elsif state == 'data_transfer'
    if data == 'complete'
      ['disconnect', data]
    else
      ['data_transfer', data]
    end
  elsif state == 'error'
    ['disconnect', data]
  elsif state == 'disconnect'
    ['end', data]
  else
    ['end', data]
  end
end

def run_network_protocol(data_sequence)
  current_state = 'start'
  data_sequence.each do |data|
    current_state, data = process_state(current_state, data)
    break if current_state == 'end'
  end
end

run_network_protocol(['success', 'complete'])