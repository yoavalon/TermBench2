def state_machine
  state = 'init'
  data = []
  loop do
    if state == 'init'
      state = 'open'
    elsif state == 'open'
      data << 'connection_opened'
      state = 'data_transfer'
    elsif state == 'data_transfer'
      data << 'data_received'
      state = 'close'
    elsif state == 'close'
      data << 'connection_closed'
      state = 'init'
    end
  end
end

def main
  state_machine
end

main