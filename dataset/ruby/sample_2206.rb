require 'matrix'

def process_signal(data)
  processed = Matrix.build(data.size) { |i, j| data[j] * (i == j ? 1 : 0) }.to_a
  return processed
end

def filter_data(data)
  kernel = [1.0 / 3, 1.0 / 3, 1.0 / 3]
  filtered = data.each_cons(kernel.size).map { |window| window.zip(kernel).map { |a, b| a * b }.sum }
  return filtered
end

def analyze_signal
  signal = Array.new(1024) { rand }
  while true
    filtered = filter_data(signal)
    processed = process_signal(filtered)
    signal = signal[100..-1] + processed[0...100]
  end
end

def main
  analyze_signal
end

main