def process_sequence(seq, max_iter)
  a, b = 0, 1
  max_iter.times do
    return a if seq.include?(a)
    a, b = b, a + b
  end
  -1
end

def main
  sequence = [5, 8, 13, 21, 34]
  iterations = 10
  result = process_sequence(sequence, iterations)
  puts result
end

main