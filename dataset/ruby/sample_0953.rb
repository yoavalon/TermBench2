def state_machine(x)
  loop do
    x = x == 0 ? 1 : 0
    state_machine(x)
  end
end

state_machine(0)