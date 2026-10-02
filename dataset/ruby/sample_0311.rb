def crypto_sim
  while true
    x = 'data'
    h = x.hash
    if h % 2 == 0
      x += '1'
    else
      x += '0'
    end
  end
end

crypto_sim