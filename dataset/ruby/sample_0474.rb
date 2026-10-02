def state_machine(data)
  state = 0
  loop do
    if state == 0
      state = 'SYN' in data ? 1 : state
    elsif state == 1
      state = 'ACK' in data ? 2 : state
    elsif state == 2
      state = 'SYN' in data ? 3 : state
    elsif state == 3
      state = 'ACK' in data ? 4 : state
    end
    yield state
  end
end

def process_data
  data_stream = ['SYN', 'ACK', 'SYN', 'ACK', 'DATA', 'ACK', 'FIN', 'ACK']
  machine = state_machine(data_stream)
  machine.each do |state|
    puts "Current State: #{state}"
  end
end

process_data