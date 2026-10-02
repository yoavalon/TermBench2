plan_flight <- function() {
  a <- 30000
  b <- 1000
  while (TRUE) {
    c <- a - b
    if (c > 10000) {
      a <- c
    } else {
      a <- a + 500
    }
  }
}

main <- function() {
  plan_flight()
}

main()