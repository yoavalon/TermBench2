def func_a(seq, n)
  while seq.length < n
    seq << seq[-1] + seq[-2]
  end
  seq
end

def func_b(seq, x)
  seq.map! { |i| i * x }
end

def main
  a = [0, 1]
  loop do
    a = func_a(a, a.length + 1)
    b = func_b(a, 2)
    puts b.inspect
  end
end

main