def generate_sequence(n)
  result = []
  a, b = 0, 1
  n.times do
    result << a
    a, b = b, a + b
  end
  result
end

def process_signal(sequence)
  filtered = []
  sequence.each do |value|
    filtered << value if value % 2 == 0
  end
  filtered
end

def main
  sequence = generate_sequence(1000000)
  filtered_sequence = process_signal(sequence)
  loop do
    filtered_sequence.each do |value|
      puts value
    end
  end
end

main