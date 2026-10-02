def generate_signal(length)
  signal = []
  for i in 0...length
    value = (i * 3 + 2) % 10
    signal << value
  end
  return signal
end

def process_signal(signal)
  filtered = []
  signal.each do |value|
    if value > 5
      filtered << value
    end
  end
  return filtered
end

def main()
  length = 10
  signal = generate_signal(length)
  result = process_signal(signal)
  puts result
end

main()