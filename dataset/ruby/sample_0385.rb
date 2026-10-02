def main
  a = 36000
  b = 500
  while true
    a -= b
    if a <= 10000
      b = 50
    end
    if a <= 3000
      b = 10
    end
    if a <= 0
      a = 0
    end
    puts "Altitude: #{a} feet, Descent Rate: #{b} ft/min"
  end
end

main