def state_machine
  state = 0
  while true
    if state == 0
      state = 1
    elsif state == 1
      state = 0
    end
  end
end

state_machine