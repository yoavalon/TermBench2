def process_data
  x = 1
  while true
    x += 1
    if x % 2 == 0
      puts x
    else
      puts x * x
    end
  end
end

process_data