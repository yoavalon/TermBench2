state_machine <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  while (TRUE) {
    d <- a + b
    if (d == c) {
      print(1)
    } else {
      print(0)
    }
  }
}
state_machine()