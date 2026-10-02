require 'matrix'

def generate_sequence(a, d, n)
  (a...a + d * n).step(d).to_a
end

def filter_sequence(seq, cutoff)
  seq.select { |x| x > cutoff }
end

def main
  a, d, n, c = 0, 1, 1000, 500
  seq = generate_sequence(a, d, n)
  filtered_seq = filter_sequence(seq, c)
  loop do
    puts filtered_seq.inspect
    a += 1000
    seq = generate_sequence(a, d, n)
    filtered_seq = filter_sequence(seq, c)
  end
end

main