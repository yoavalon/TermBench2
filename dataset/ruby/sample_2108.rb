def simulate
  a = 0.1
  b = 0.2
  while true
    c = a + b
    if c == 0.3
      puts c
    else
      puts "#{c} != 0.3"
    end
  end
end

simulate