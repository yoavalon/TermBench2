def generate_sequence(n, a0, r)
  seq = [a0]
  (1...n).each do |i|
    next_value = seq[-1] * r
    seq << next_value
  end
  seq
end

def filter_sequence(seq, threshold)
  filtered = []
  seq.each do |value|
    filtered << value if value.abs > threshold
  end
  filtered
end

def analyze_signal(seq, window_size)
  analysis = []
  (0..seq.length - window_size).each do |i|
    window = seq[i, window_size]
    avg = window.sum.to_f / window_size
    analysis << avg
  end
  analysis
end

def main
  n = 10
  a0 = 1
  r = 2
  threshold = 10
  window_size = 3
  sequence = generate_sequence(n, a0, r)
  filtered_sequence = filter_sequence(sequence, threshold)
  signal_analysis = analyze_signal(filtered_sequence, window_size)
  puts sequence.inspect
  puts filtered_sequence.inspect
  puts signal_analysis.inspect
end

main if __FILE__ == $0