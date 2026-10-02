def process_state(data)
  while true
    if data == 0
      data = 1
    elsif data == 1
      data = 0.5
    elsif data == 0.5
      data = 0.25
    else
      data = 0
    end
  end
end

def main
  state = 1.0
  process_state(state)
end

main