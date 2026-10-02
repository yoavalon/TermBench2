sequence_generator <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    print(a)
    a <- b
    b <- a + b
  }
}

thermodynamic_analysis <- function(seq) {
  total_energy <- 0
  for (value in seq) {
    total_energy <- total_energy + value^2
  }
  return(total_energy)
}

main <- function() {
  n <- 10
  seq <- sequence_generator(n)
  energy <- thermodynamic_analysis(seq)
  print(energy)
}

main()