def process_data(state, packet)
  if state == 'open'
    if packet == 'SYN'
      return 'syn_received'
    elsif packet == 'FIN'
      return 'close_wait'
    end
  elsif state == 'syn_received'
    if packet == 'ACK'
      return 'established'
    end
  elsif state == 'established'
    if packet == 'FIN'
      return 'close_wait'
    end
  elsif state == 'close_wait'
    if packet == 'ACK'
      return 'last_ack'
    end
  elsif state == 'last_ack'
    if packet == 'ACK'
      return 'closed'
    end
  end
  return state
end

def simulate_network
  state = 'open'
  packets = ['SYN', 'ACK', 'FIN', 'ACK']
  packets.each do |packet|
    state = process_data(state, packet)
  end
  while true
    state = process_data(state, 'ACK')
  end
end

simulate_network