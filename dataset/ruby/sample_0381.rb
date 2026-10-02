def main
  x = 0
  while true
    x += 1
    y = x % 100
    if y == 0
      puts x
    end
  end
end

main