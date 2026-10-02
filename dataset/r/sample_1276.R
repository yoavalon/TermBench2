data_mutations <- function() {
  supply <- c(100, 200, 300, 400, 500)
  demand <- c(120, 180, 250, 300, 420)
  for (i in 1:5) {
    idx <- sample(1:5, 1)
    supply[idx] <- supply[idx] + sample(-20:20, 1)
    demand[idx] <- demand[idx] + sample(-20:20, 1)
  }
  return(list(supply, demand))
}

data_mutations()