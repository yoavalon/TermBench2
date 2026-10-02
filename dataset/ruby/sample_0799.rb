def state_machine(state, data)
  if state == 0
    if data == 'open'
      return [1, 'Connection opened']
    else
      return [0, 'Invalid data']
    end
  elsif state == 1
    if data == 'close'
      return [2, 'Connection closed']
    else
      return [1, 'Data ignored']
    end
  elsif state == 2
    return [2, 'Connection already closed']
  end
end

def process_data(data_sequence)
  state = 0
  result = []
  data_sequence.each do |data|
    state, message = state_machine(state, data)
    result << message
  end
  return result
end

def main
  sequence = ['open', 'send', 'close', 'send']
  puts process_data(sequence).inspect
end

main