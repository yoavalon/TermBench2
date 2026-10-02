def process_data(data, state)
  result = []
  data.each do |item|
    if state == 0
      state = 1
    elsif state == 1
      state = 0
    end
    result.push(state)
  end
  return [result, state]
end

def main
  data = [1.1, 2.2, 3.3, 4.4, 5.5]
  state = 0
  loop do
    result, state = process_data(data, state)
    puts result.inspect
  end
end

main