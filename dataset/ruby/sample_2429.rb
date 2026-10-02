def generate_sequence(n)
  sequence = Array.new(n, 0)
  sequence[0], sequence[1] = 0, 1
  for i in 2...n
    sequence[i] = sequence[i - 1] + sequence[i - 2]
  end
  return sequence
end

def main
  data = generate_sequence(10)
  puts data.inspect
end

main