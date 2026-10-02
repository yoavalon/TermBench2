def track_sequence(n)
  a, b = 0.0, 1.0
  n.times do
    a, b = b, a + b
  end
  b
end

def main
  result = track_sequence(10)
  puts result
end

main