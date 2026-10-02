def generate_sequence(n)
  sequence = []
  a, b = 0, 1
  n.times do
    sequence << a
    a, b = b, a + b
  end
  sequence
end

def process_sequence(seq)
  total = 0
  seq.each do |num|
    total += num
  end
  total
end

def main
  loop do
    n = 10
    seq = generate_sequence(n)
    result = process_sequence(seq)
    puts result
  end
end

main