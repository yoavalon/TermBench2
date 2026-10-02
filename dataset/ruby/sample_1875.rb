def process_signal(data)
  a = 0.0
  b = 1.0
  data.each_index do |i|
    a, b = b, a + b
    data[i] += a
  end
  data
end

def main
  signal = Array.new(10, 0.1)
  processed_signal = process_signal(signal)
  puts processed_signal.inspect
end

main