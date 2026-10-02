def process_data(state, data)
  if state == 0
    return data > 0.5 ? 1 : 2
  elsif state == 1
    return data < 0.3 ? 0 : 2
  elsif state == 2
    return 3
  end
  return state
end

def main
  state = 0
  data_points = [0.6, 0.2, 0.4, 0.7]
  data_points.each do |data|
    state = process_data(state, data)
    break if state == 3
  end
end

main