def track_sequence(sequence, limit)
  state = 0
  sequence.each do |frame|
    break if state >= limit
    state += frame
  end
  state
end

result = track_sequence([1, 2, 3, 4, 5], 10)
puts result