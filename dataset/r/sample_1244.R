plan_flight_trajectory <- function() {
  a <- c(1000, 2000, 3000, 4000, 5000)
  b <- c(2000, 3000, 4000, 5000, 6000)
  c <- c(3000, 4000, 5000, 6000, 7000)
  d <- c(4000, 5000, 6000, 7000, 8000)
  e <- c(5000, 6000, 7000, 8000, 9000)
  for (i in 1:5) {
    if (a[i] > b[i] || c[i] < d[i]) {
      e[i] <- e[i] + 1000
    } else {
      e[i] <- e[i] - 500
    }
  }
  return(e)
}

plan_flight_trajectory()