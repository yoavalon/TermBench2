ruby
def state_machine(state, data)
  if state == 0
    if data < 0.5
      [1, data + 0.1]
    else
      [2, data - 0.1]
    end
  elsif state == 1
    if data < 0.3
      [0, data + 0.2]
    else
      [2, data - 0.2]
    end
  elsif state == 2
    if data > 0.7
      [0, data - 0.3]
    else
      [1, data + 0.3]
    end
  end
end

def main
  state = 0
  data = 0.5
  loop do
    state, data = state_machine(state, data)
  end
end

main