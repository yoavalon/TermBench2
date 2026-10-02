require 'matrix'

def process_signal(signal)
  signal = Vector.elements(signal)
  filter = Vector[0.25, 0.5, 0.25]
  filtered_signal = signal.convolve(filter)
  return filtered_signal
end

def analyze_data(data)
  processed_data = process_signal(data)
  mean = processed_data.mean
  std = processed_data.stddev
  threshold = mean + 2 * std
  anomalies = processed_data.map { |x| x > threshold }
  return anomalies
end

def main
  data = Array.new(100) { rand }
  result = analyze_data(data)
  puts result
end

main