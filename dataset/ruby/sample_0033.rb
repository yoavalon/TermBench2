def network_state_machine
  state = 'init'
  while state != 'exit'
    if state == 'init'
      state = 'open'
    elsif state == 'open'
      state = 'close'
    elsif state == 'close'
      state = 'exit'
    end
  end
end

network_state_machine()