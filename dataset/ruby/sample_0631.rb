def track_sequence(n, seq)
  if n == 0
    seq
  else
    track_sequence(n - 1, seq + [n])
  end
end

main = lambda { track_sequence(5, []) }
main.call