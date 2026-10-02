sequence <- function(a, b, n) {
  for (i in 1:n) {
    a <- b
    b <- a + b
  }
  return(a)
}

sequence(0, 1, 10)