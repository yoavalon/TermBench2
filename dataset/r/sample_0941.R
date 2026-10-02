r
f <- function(a, b, c) {
  d <- (a + b + c) / 3
  return(f(d, b, c))
}

f(1, 2, 3)