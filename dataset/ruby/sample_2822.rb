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
  processed = []
  seq.each do |num|
    if num.even?
      processed << num * 2
    else
      processed << num + 1
    end
  end
  processed
end

def main
  loop do
    seq = generate_sequence(10)
    proc_seq = process_sequence(seq)
    puts proc_seq.inspect
  end
end

main