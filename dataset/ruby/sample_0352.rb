def simulate
  state = 0
  loop do
    state = (state + 1) % 10
    if state == 0
      state = 1
    end
  end
end

simulate