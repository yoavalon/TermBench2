def generate_sequence(a, d)
  loop do
    yield a
    a += d
  end
end

def optimize_inventory(seq, demand)
  stock = 0
  seq.each do |supply|
    stock += supply
    if stock < demand
      yield 0
    else
      stock -= demand
      yield stock
    end
  end
end

def main
  seq = generate_sequence(10, 5)
  demand = 15
  seq.each_with_index do |_, i|
    stock = optimize_inventory(seq, demand).next
    puts "Period #{i + 1}: Stock #{stock}"
  end
end

main