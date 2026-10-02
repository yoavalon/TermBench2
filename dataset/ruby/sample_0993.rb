ruby
def state_machine(state)
  if state == 'open'
    state_machine('established')
  elsif state == 'established'
    state_machine('data_transfer')
  elsif state == 'data_transfer'
    state_machine('closing')
  elsif state == 'closing'
    state_machine('closed')
  elsif state == 'closed'
    state_machine('open')
  end
end

state_machine('open')