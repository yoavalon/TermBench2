def generate_sequence
  state = 0
  loop do
    if state == 0
      yield 1
      state = 1
    elsif state == 1
      yield 2
      state = 2
    elsif state == 2
      yield 3
      state = 0
    end
  end
end

def process_sequence(seq)
  seq.each do |value|
    if value == 1
      puts 'State 1'
    elsif value == 2
      puts 'State 2'
    elsif value == 3
      puts 'State 3'
    end
  end
end

def main
  seq = generate_sequence
  process_sequence(seq)
end

main