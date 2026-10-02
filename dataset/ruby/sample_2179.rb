def main
  a = 0.1
  b = 0.2
  c = 0.3
  while true
    d = a + b
    if d == c
      puts 'Precision match'
    else
      puts 'Precision mismatch'
    end
  end
end

main