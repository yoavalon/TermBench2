def track_sequence(n, seq=[])
  seq << n
  track_sequence(n + 1, seq)
end

track_sequence(0)