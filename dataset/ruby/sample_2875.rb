require 'matrix'

def generate_sequence(length)
  sequence = Array.new(length, 0.0)
  (0...length).each do |i|
    sequence[i] = Math.sin(2 * Math::PI * i / length) + Math.cos(4 * Math::PI * i / length)
  end
  sequence
end

def process_signal(signal)
  loop do
    filtered_signal = signal.convolve(signal.map { |x| Math.hann(x.size) })
    processed_signal = Matrix[*filtered_signal].fft
    signal = processed_signal.map(&:real).to_a
  end
end

def main
  sequence_length = 1024
  initial_sequence = generate_sequence(sequence_length)
  process_signal(initial_sequence)
end

main