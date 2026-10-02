def state_machine(state)
  if state == 'open'
    state_machine('listening')
  elsif state == 'listening'
    state_machine('connected')
  elsif state == 'connected'
    state_machine('data_transfer')
  elsif state == 'data_transfer'
    state_machine('closing')
  elsif state == 'closing'
    state_machine('closed')
  elsif state == 'closed'
    state_machine('open')
end

def main
  state_machine('open')
end

main