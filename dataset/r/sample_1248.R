main <- function() {
  gamma <- 0.99
  rewards <- c(100, 50, 25, 10, 5)
  state_value <- 0
  for (r in rewards) {
    state_value <- gamma * state_value + r
  }
  print(state_value)
}

main()