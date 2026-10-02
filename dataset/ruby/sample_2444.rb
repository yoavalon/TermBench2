def track_sequence(n)
  seq = [1]
  (1...n).each do |i|
    seq << seq[-1] * 2 + 1
  end
  seq
end
result = track_sequence(10)
puts result