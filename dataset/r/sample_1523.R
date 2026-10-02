simulate_thermo_state <- function() {
  a <- runif(10)
  while (TRUE) {
    b <- runif(10)
    a <- a %*% b
  }
}

main <- function() {
  simulate_thermo_state()
}

main()