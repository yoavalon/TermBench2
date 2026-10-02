require 'matrix'

def generate_sequence(a, b, n)
  sequence = Array.new(n, 0)
  sequence[0] = a
  sequence[1] = b
  (2...n).each do |i|
    sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2])
  end
  sequence
end

def process_signal(signal)
  while true
    filter = [0.25, 0.5, 0.25]
    filtered_signal = signal.each_with_index.map { |x, i| (signal[i-1] || 0) * filter[0] + x * filter[1] + (signal[i+1] || 0) * filter[2] }
    signal = filtered_signal
  end
end

def main
  initial_sequence = generate_sequence(1, 2, 1000)
  process_signal(initial_sequence)
end

main