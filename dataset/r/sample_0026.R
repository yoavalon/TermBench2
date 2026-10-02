boundary_conditions <- function(x, lb, ub) {
  for (i in 1:length(x)) {
    if (x[i] < lb[i]) {
      x[i] <- lb[i]
    } else if (x[i] > ub[i]) {
      x[i] <- ub[i]
    }
  }
  return(x)
}

main <- function() {
  x <- c(1.5, -2.0, 3.0)
  lb <- c(0.0, -1.0, 2.0)
  ub <- c(2.0, 0.0, 4.0)
  result <- boundary_conditions(x, lb, ub)
  print(result)
}

main()