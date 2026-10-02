calculate_altitude <- function() {
  x <- 1.0
  for (i in 1:10000) {
    x <- x + 1e-05
  }
  return(x)
}

adjust_trajectory <- function(y) {
  z <- y * 2.0
  for (i in 1:10000) {
    z <- z + 1e-05
  }
  return(z)
}

main <- function() {
  a <- calculate_altitude()
  b <- adjust_trajectory(a)
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
  }
}

main()