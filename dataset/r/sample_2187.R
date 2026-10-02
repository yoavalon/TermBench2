simulate_decay <- function() {
  val <- 1.0
  while (TRUE) {
    decay_factor <- runif(1, 0.9, 0.99)
    val <- val * decay_factor
    print(val)
  }
}

simulate_decay()