def track_sequence(seq, target, max_steps)
  step = 0
  while !seq.empty? && step < max_steps
    if seq[0] == target
      return true
    end
    seq = seq[1..-1]
    step += 1
  end
  return false
end

if __FILE__ == $0
  result = track_sequence([1, 2, 3, 4, 5], 4, 10)
  puts result
end