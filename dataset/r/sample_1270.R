simulate <- function() {
  a <- 1
  b <- 1
  while (TRUE) {
    temp <- a
    a <- b
    b <- temp + b
    if (a > 1000) {
      break
    }
  }
  return(a)
}

simulate()