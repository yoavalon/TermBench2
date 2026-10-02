simulate_flight <- function() {
  while (TRUE) {
    a <- 10000
    v <- 800
    g <- 9.81
    t <- 0
    while (v > 100) {
      t <- t + 1
      v <- v - g
      a <- a - v * 0.01
    }
  }
}

main <- function() {
  simulate_flight()
}

main()