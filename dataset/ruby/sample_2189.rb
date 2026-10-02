def simulate(a, b, c)
  loop do
    a, b, c = b, c, (a + b + c) / 3.0
    yield a, b, c
  end
end

def main
  simulate(1.0, 2.0, 3.0) do |x, y, z|
    puts "#{x.round(5)}, #{y.round(5)}, #{z.round(5)}"
  end
end

main