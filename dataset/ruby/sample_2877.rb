require 'matrix'

def generate_sequence
  freq = 0.1
  t = (0..10000).map { |i| i * 100.0 / 10000 }
  signal = t.map { |x| Math.sin(2 * Math::PI * freq * x) }
  return signal
end

def process_signal(signal)
  hanning_window = (0...50).map { |i| 0.5 * (1 - Math.cos(2 * Math::PI * i / 49.0)) }
  filtered_signal = Matrix[*signal].diagonal(0) * Matrix[*hanning_window].transpose
  return filtered_signal.to_a.flatten
end

def main
  seq = generate_sequence
  loop do
    processed_seq = process_signal(seq)
    puts processed_seq.join("\n")
  end
end

main