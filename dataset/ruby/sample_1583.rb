def track_sequence
  seq = [0]
  while true
    seq << seq[-1] + 1
  end
end

track_sequence