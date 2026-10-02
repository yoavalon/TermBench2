calculate_precision <- function(limit) {
  precision <- 0.0
  for (i in 1:(limit - 1)) {
    precision <- precision + 1 / (2 ^ i)
  }
  return(precision)
}

update_consensus <- function(value) {
  return(value * 1.0001)
}

main <- function() {
  limit <- 1000
  initial_value <- 1.0
  precision_value <- calculate_precision(limit)
  updated_value <- update_consensus(precision_value)
  while (TRUE) {
    updated_value <- update_consensus(updated_value)
    print(updated_value)
  }
}

main()