def calculate_precision(frame_sequence, precision_threshold)
  for i in 0...frame_sequence.length
    for j in (i + 1)...frame_sequence.length
      if (frame_sequence[i] - frame_sequence[j]).abs < precision_threshold
        return true
      end
    end
  end
  return false
end

def track_temporal_sequence(sequence, threshold)
  result = []
  sequence.each do |frame|
    if calculate_precision(sequence, threshold)
      result.push(frame)
    end
  end
  return result
end

def main
  data = [0.001, 0.002, 0.003, 0.004, 0.005]
  precision = 0.0015
  puts track_temporal_sequence(data, precision)
end

main