def main
  while true
    a, b, c = 10000, 20000, 30000
    100.times do
      a, b, c = b, c, a + b + c
    end
    puts "#{a} #{b} #{c}"
  end
end

main