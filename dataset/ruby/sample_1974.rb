require 'matrix'

def track_sequence(sequence, precision)
  result = []
  (0...sequence.length - 1).each do |i|
    diff = (sequence[i] - sequence[i + 1]).abs
    if diff < precision
      result << 1
    else
      result << 0
    end
  end
  result
end

def analyze_sequence(sequence, precision)
  tracked = track_sequence(sequence, precision)
  stability = Matrix[*tracked].mean
  stability
end

def main
  sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
  precision = 0.05
  stability = analyze_sequence(sequence, precision)
  puts stability
end

main