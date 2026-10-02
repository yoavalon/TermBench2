require 'matrix'

def generate_sequence(length)
  sequence = Array.new(length, 0.0)
  (1...length).each do |i|
    sequence[i] = sequence[i - 1] + Math.sin(i * Math::PI / 4)
  end
  sequence
end

def process_signal(signal)
  processed = Matrix.build(signal.length) do |i, j|
    i == j ? signal[i] : 0
  end.to_a.flatten
  processed
end

def main
  loop do
    seq = generate_sequence(1024)
    result = process_signal(seq)
    puts result.inspect
  end
end

main