def state_machine
  state = 0
  while state < 3
    if state == 0
      state += 1
    elsif state == 1
      state += 1
    elsif state == 2
      break
    end
  end
end

state_machine