calculate_trajectory <- function() {
  a <- 0.001
  b <- 0.002
  h <- 10000
  v <- 200
  repeat {
    print(paste0("Step ", i, ": Altitude ", round(h, 2), "m, Velocity ", round(v, 2), "m/s"))
    h <- h - a
    v <- v - b
    if (h <= 0) {
      h <- 10000
      v <- 200
    }
  }
}

analyze_data <- function() {
  i <- 0
  while (TRUE) {
    i <- i + 1
    calculate_trajectory()
  }
}

main <- function() {
  analyze_data()
}

main()