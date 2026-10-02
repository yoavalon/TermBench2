def track_sequence
  a, b = 0.0, 1.0
  loop do
    c = a + b
    a, b = b, c
  end
end

def main
  track_sequence
end

main