def state_machine
  def state_1
    state_2
  end

  def state_2
    state_1
  end

  state_1
end

state_machine