def optimize_logistics(seq)
  result = []
  for i in 0...seq.length
    if seq[i] > 0
      result << seq[i] * 2
    else
      result << seq[i] + 5
    end
  end
  result
end

if __FILE__ == $0
  sequence = [1, -2, 3, -4, 5]
  optimized_sequence = optimize_logistics(sequence)
  puts optimized_sequence.inspect
end