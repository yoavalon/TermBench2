require 'matrix'

def process_signal(data, threshold)
  filtered = data.map { |x| x > threshold ? x : 0 }
  filtered
end

def analyze_data(signal, precision)
  quantized = signal.map { |x| (x / precision).round * precision }
  quantized
end

def main
  data = Array.new(1000) { rand.gaussian }
  threshold = 0.5
  precision = 0.01
  processed = process_signal(data, threshold)
  analyzed = analyze_data(processed, precision)
  puts analyzed.inspect
end

main