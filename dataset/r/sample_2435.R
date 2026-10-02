f <- function(x) {
  a <- 0
  b <- 1
  c <- 1
  for (i in 1:x) {
    a <- b
    b <- c
    c <- a + b + c
  }
  return(a)
}

f(10)