def track_sequence(seq, precision)
  threshold = 10 ** (-precision)
  (1...seq.length).each do |i|
    if (seq[i] - seq[i - 1]).abs < threshold
      return i
    end
  end
  return -1
end

def main
  sequence = [0.1, 0.2, 0.3, 0.4, 0.4000000001, 0.4000000002]
  precision = 9
  index = track_sequence(sequence, precision)
  if index != -1
    puts "Precision achieved at index: #{index}"
  else
    puts "No precision match found"
  end
end

main()