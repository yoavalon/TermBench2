def main

def transition(state)
  return (state + 1) % 3
end

state = 0
while true
  state = transition(state)
  puts state
end

end

main