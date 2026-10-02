def sequence_generator(n)
  a, b = 0, 1
  (0...n).each do |i|
    yield a
    a, b = b, a + b
  end
end

def thermodynamic_analysis(seq)
  total_energy = 0
  seq.each do |value|
    total_energy += value ** 2
  end
  total_energy
end

def main
  n = 10
  seq = []
  sequence_generator(n) { |value| seq << value }
  energy = thermodynamic_analysis(seq)
  puts energy
end

main