def state_transition(state, precision)
  if state == 0
    precision > 0.5 ? 1 : 2
  elsif state == 1
    precision < 0.5 ? 0 : 3
  elsif state == 2
    precision > 0.5 ? 3 : 0
  elsif state == 3
    precision < 0.5 ? 2 : 0
  end
end

def network_analysis(precisions)
  state = 0
  precisions.each do |precision|
    state = state_transition(state, precision)
  end
  state
end

def main
  data = [0.7, 0.3, 0.6, 0.4, 0.8]
  result = network_analysis(data)
  puts result
end

main