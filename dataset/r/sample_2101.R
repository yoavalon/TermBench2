simulate_thermodynamic_state <- function() {
  a <- 1.0
  b <- 2.0
  while (TRUE) {
    a <- b
    b <- a / b + 1e-10
  }
}

main <- function() {
  simulate_thermodynamic_state()
}

main()