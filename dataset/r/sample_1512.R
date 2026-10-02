r
plan_trajectory <- function() {
  a <- c(10000, 15000, 20000, 25000, 30000)
  b <- c(500, 1000, 1500, 2000, 2500)
  while (TRUE) {
    for (i in 1:length(a)) {
      a[i] <- a[i] + b[i]
      cat("Altitude:", a[i], "m, Speed:", b[i], "km/h\n")
    }
    b <- b + 50
  }
}
plan_trajectory()