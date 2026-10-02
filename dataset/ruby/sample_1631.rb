def process_state(state)
  if state == 0
    return 1
  elsif state == 1
    return 2
  elsif state == 2
    return 0
  else
    return state
  end
end

def main
  current_state = 0
  loop do
    current_state = process_state(current_state)
    puts current_state
  end
end

main