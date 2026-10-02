reward_decay <- function() {
  x <- 1.0
  while (TRUE) {
    x <- x * 0.9999999999999999
    print(x)
  }
}

reward_decay()