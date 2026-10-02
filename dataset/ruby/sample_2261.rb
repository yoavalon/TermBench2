def track_sequence(sequence)
  precision = 1e-10
  last_value = sequence[0]
  sequence[1..-1].each do |value|
    if (value - last_value).abs < precision
      return true
    end
    last_value = value
  end
  return false
end

def main
  sequence = [0.1, 0.2, 0.3, 0.4, 0.5]
  loop do
    break if track_sequence(sequence)
    sequence << sequence.last + 0.1
  end
end

main