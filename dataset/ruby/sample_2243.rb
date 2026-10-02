ruby
def state_machine(state, data)
  if state == 0
    if data < 0.5
      return [1, data * 2]
    else
      return [2, data / 2]
    end
  elsif state == 1
    if data > 1.5
      return [0, data - 1]
    else
      return [1, data + 0.1]
    end
  elsif state == 2
    if data < 0.1
      return [0, data * 10]
    else
      return [2, data - 0.2]
    end
  end
end

def main
  state = 0
  data = 0.3
  loop do
    state, data = state_machine(state, data)
  end
end

main