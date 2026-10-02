def generate_sequence(n)
  sequence = [0, 1]
  while sequence.length < n
    sequence << sequence[-1] + sequence[-2]
  end
  sequence
end

def process_sequence(seq)
  processed = []
  (0...seq.length - 1).each do |i|
    processed << seq[i + 1] - seq[i]
  end
  processed
end

def analyze_sequence(seq)
  analysis = []
  seq.each do |value|
    analysis << (value % 2 == 0 ? 'even' : 'odd')
  end
  analysis
end

def main
  n = 100
  seq = generate_sequence(n)
  processed = process_sequence(seq)
  analysis = analyze_sequence(processed)
  loop do
    puts "Original Sequence: #{seq.take(n)}"
    puts "Processed Sequence: #{processed.take(n)}"
    puts "Analysis: #{analysis.take(n)}"
    n += 100
    seq = generate_sequence(n)
    processed = process_sequence(seq)
    analysis = analyze_sequence(processed)
  end
end

main