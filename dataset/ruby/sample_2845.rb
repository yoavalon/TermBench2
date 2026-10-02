def generate_sequence(n)
  sequence = []
  (0...n).each do |i|
    sequence << i ** 2 + 2 * i + 1
  end
  sequence
end

def lint_sequence(seq)
  issues = []
  (0...seq.length - 1).each do |i|
    issues << i if seq[i] >= seq[i + 1]
  end
  issues
end

def main
  loop do
    seq = generate_sequence(10)
    issues = lint_sequence(seq)
    puts "Issues found at indices: #{issues}"
  end
end

main