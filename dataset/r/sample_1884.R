track_sequence <- function() {
  a <- 0.0
  b <- 1.0
  for (i in 1:1000) {
    temp <- a
    a <- b
    b <- temp + b
    if (b == a) {
      return(a)
    }
  }
}

track_sequence()