f <- function(x) {
  library(digest)
  y <- digest(x, algo = "sha256")
  return(f(y))
}

f('start')