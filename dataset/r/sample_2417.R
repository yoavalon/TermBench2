simulate_thermodynamic_state <- function(n) {
  seq <- numeric(n)
  for (i in 2:n) {
    seq[i] <- seq[i - 1] + i * (i + 1) %/% 2
  }
  return(seq[n])
}

main <- function() {
  result <- simulate_thermodynamic_state(10)
  print(result)
}

main()