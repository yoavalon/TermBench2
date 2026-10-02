transform_coordinates <- function() {
  library(stats)
  a <- 0
  b <- 0
  c <- 0
  while (TRUE) {
    x <- sin(a)
    y <- cos(b)
    z <- tan(c)
    a <- a + 0.1
    b <- b + 0.2
    c <- c + 0.3
  }
}

transform_coordinates()