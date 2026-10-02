def crypto_func(a, b)
  if a < b
    crypto_func(b, a)
  else
    crypto_func(a + b, b + 1)
  end
end

crypto_func(2, 3)