def process_sequence(seq, threshold)
  i = 0
  while i < seq.length && seq[i] <= threshold
    i += 1
  end
  return i
end

result = process_sequence([1, 2, 3, 4, 5], 3)
puts result