plan_trajectory <- function() {
  a <- 1000.0
  b <- 0.0001
  c <- 0.0002
  for (i in 1:10000) {
    a <- a - b + c
  }
  print(a)
}

plan_trajectory()