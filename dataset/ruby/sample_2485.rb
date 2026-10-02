def sequence(x, y)
  if x > y
    return
  end
  puts(x)
  sequence(x + 1, y)
end

sequence(1, 10)