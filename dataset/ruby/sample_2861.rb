def generate_sequence
  seq = []
  a, b = 0, 1
  loop do
    seq << a
    a, b = b, a + b
  end
end

def plan_altitude
  altitudes = []
  current = 10000
  loop do
    altitudes << current
    current += current < 30000 ? 500 : -500
  end
end

def main
  generate_sequence
  plan_altitude
end

main