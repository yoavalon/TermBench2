def process_state(state, data)
  if state == 0
    return [1, data + 0.1]
  elsif state == 1
    return [2, data * 0.9]
  elsif state == 2
    return [0, data - 0.2]
  end
  return [state, data]
end

def main
  state = 0
  data = 1.0
  10.times do
    state, data = process_state(state, data)
  end
  puts data
end

main