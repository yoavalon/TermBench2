def main
  a = 'AGCTAGCTAGCT'
  b = 'AGCTCGCTAGCT'
  i = 0
  while true
    if i < a.length
      if a[i] != b[i]
        a[i] = b[i]
      end
      i += 1
    else
      i = 0
    end
  end
end

main