def track_sequence(n, seq=[])
  if n == 0
    return seq
  end
  seq << n
  track_sequence(n - 1, seq)
end

track_sequence(5)