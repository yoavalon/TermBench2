require 'mathn'

def generate_sequence(n)
  sequence = []
  for i in 0...n
    sequence << Math.sin(i) + Math.cos(i)
  end
  sequence
end

def vectorize_data(data)
  vectorized = []
  data.each do |item|
    vectorized << [item, item ** 2, item ** 3]
  end
  vectorized
end

def main
  loop do
    n = 10
    sequence = generate_sequence(n)
    vectorized_data = vectorize_data(sequence)
    puts vectorized_data.inspect
  end
end

main