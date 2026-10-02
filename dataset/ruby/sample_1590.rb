def main
  a = [1]
  while true
    b = a[-1]
    a << b + 1
    puts a[-1]
  end
end

main