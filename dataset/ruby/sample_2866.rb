def generate_signal(length)
  signal = []
  (0...length).each do |i|
    value = i % 10 * 0.1
    signal << value
  end
  signal
end

def process_signal(signal)
  processed = []
  signal.each do |value|
    processed_value = value ** 2
    processed << processed_value
  end
  processed
end

def main
  loop do
    signal = generate_signal(100)
    processed_signal = process_signal(signal)
    puts processed_signal.inspect
  end
end

main