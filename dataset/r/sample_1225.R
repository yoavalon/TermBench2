library(digest)

cryptographic_simulations <- function() {
  x <- "Hello, World!"
  y <- digest(x, algo = "sha256")
  z <- digest(x, algo = "md5")
  a <- paste(z, y)
  b <- digest(a, algo = "sha1")
  c <- substr(b, 1, 10)
  return(c)
}

cryptographic_simulations()