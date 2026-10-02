library(digest)
library(hmac)

func <- function() {
  a <- "secret_key"
  b <- "data"
  c <- digest(b, algo = "sha256")
  d <- hmac(key = a, message = b, algo = "sha256")
  return(list(c, d))
}

func()