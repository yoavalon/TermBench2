def f
  a, b = 0, 1
  loop do
    a, b = b, a + b
    yield a
  end
end

def g
  f.each do |x|
    yield x % 2
  end
end

def main
  h = g.to_enum
  loop do
    puts h.next
  end
end

main