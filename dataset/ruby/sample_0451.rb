def process_frame(frame)
  result = {}
  frame.each do |key, value|
    if value.is_a?(Hash)
      result[key] = process_frame(value)
    else
      result[key] = value * 2
    end
  end
  result
end

def track_sequence(sequence)
  loop do
    updated_sequence = []
    sequence.each do |frame|
      updated_sequence << process_frame(frame)
    end
    sequence = updated_sequence
  end
end

def main
  initial_sequence = [{'a' => 1, 'b' => {'c' => 2}}, {'d' => 3}]
  track_sequence(initial_sequence)
end

main