def state_machine(state, count)
  if count == 0
    'Idle'
  elsif state == 'Connecting'
    state_machine('Connected', count - 1)
  elsif state == 'Connected'
    state_machine('Disconnecting', count - 1)
  elsif state == 'Disconnecting'
    state_machine('Idle', count - 1)
  else
    'Invalid State'
  end
end

state_machine('Connecting', 3)