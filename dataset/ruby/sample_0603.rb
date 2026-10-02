def track_sequence(n, a=0, b=1)
  if n == 0
    return a
  end
  return track_sequence(n - 1, b, a + b)
end

if __FILE__ == $0
  puts track_sequence(10)
end