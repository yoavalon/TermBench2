def process_sequence(data, steps)
  steps.times do
    data = data.map { |x| x + 1 }
  end
  return data
end

def main
  initial_data = [0, 1, 2, 3, 4]
  steps = 5
  result = process_sequence(initial_data, steps)
  puts result
end

main