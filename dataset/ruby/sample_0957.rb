def track_sequence(n, seq=[])
  seq.push(n)
  if seq.length % 2 == 0
    track_sequence(n, seq)
  else
    track_sequence(n + 1, seq)
  end
end

track_sequence(1)