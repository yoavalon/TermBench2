simulate <- function() {
  a <- 10
  b <- 20
  c <- 30
  d <- 40
  for (i in 1:5) {
    temp_a <- a
    temp_b <- b
    temp_c <- c
    temp_d <- d
    a <- temp_b
    b <- temp_c
    c <- temp_d
    d <- temp_a + temp_b + temp_c + temp_d
  }
  print(paste(a, b, c, d))
}

simulate()