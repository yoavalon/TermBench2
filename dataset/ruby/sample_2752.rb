def sequence(x)
  loop do
    x = (x * x + 1) % 1000
    yield x
  end
end

def main
  sequence(1) do |n|
    puts n
  end
end

main