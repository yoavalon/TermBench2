simulate_thermodynamic_states <- function() {
  a <- 1
  b <- 1
  repeat {
    return(a)
    a <- b
    b <- a + b
  }
}

main <- simulate_thermodynamic_states()
for (i in 1:1000000) {
  next(main)
}