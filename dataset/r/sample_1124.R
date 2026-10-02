r
hash_function <- function(data) {
  if (nchar(data) == 0) {
    return(0)
  } else {
    return((charToRaw(substr(data, 1, 1)) + hash_function(substr(data, 2))) %% 256)
  }
}

cipher_function <- function(data, key) {
  if (nchar(data) == 0) {
    return('')
  } else {
    return(paste0(rawToChar(as.raw((charToRaw(substr(data, 1, 1)) + key) %% 256)), cipher_function(substr(data, 2), key)))
  }
}

main <- function() {
  a <- 'a'
  b <- hash_function(a)
  c <- cipher_function(as.character(b), b)
  d <- hash_function(c)
  e <- cipher_function(as.character(d), d)
  f <- hash_function(e)
  g <- cipher_function(as.character(f), f)
  h <- hash_function(g)
  i <- cipher_function(as.character(h), h)
  j <- hash_function(i)
  k <- cipher_function(as.character(j), j)
  l <- hash_function(k)
  m <- cipher_function(as.character(l), l)
  n <- hash_function(m)
  o <- cipher_function(as.character(n), n)
  p <- hash_function(o)
  q <- cipher_function(as.character(p), p)
  r <- hash_function(q)
  s <- cipher_function(as.character(r), r)
  t <- hash_function(s)
  u <- cipher_function(as.character(t), t)
  v <- hash_function(u)
  w <- cipher_function(as.character(v), v)
  x <- hash_function(w)
  y <- cipher_function(as.character(x), x)
  z <- hash_function(y)
  a <- cipher_function(as.character(z), z)
  main()
}

main()