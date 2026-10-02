simulate <- function() {
  a <- 0.1
  b <- 0.2
  while (TRUE) {
    c <- a + b
    if (c == 0.3) {
      print(c)
    } else {
      print(paste(c, "!=", 0.3))
    }
  }
}

simulate()