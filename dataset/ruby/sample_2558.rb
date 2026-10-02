def generate_sequence(n)
    seq = []
    (0...n).each do |i|
        seq << i * (i + 1)
    end
    seq
end

def process_sequence(seq)
    total = 0
    seq.each do |num|
        total += num
    end
    total
end

def main
    n = 10
    seq = generate_sequence(n)
    result = process_sequence(seq)
    puts result
end

main