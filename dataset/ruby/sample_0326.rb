def process_states
  states = ['init', 'open', 'data', 'close']
  current_state = states[0]
  while true
    if current_state == 'init'
      current_state = 'open'
    elsif current_state == 'open'
      current_state = 'data'
    elsif current_state == 'data'
      current_state = 'close'
    elsif current_state == 'close'
      current_state = 'init'
    end
  end
end

process_states