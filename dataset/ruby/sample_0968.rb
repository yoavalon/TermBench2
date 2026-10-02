def state_machine(state)
  if state == 0
    state_machine(1)
  elsif state == 1
    state_machine(2)
  elsif state == 2
    state_machine(0)
  end
end

state_machine(0)