r
supply_chain_optimization <- function() {

  calculate_next <- function(arr) {
    return(c(arr[length(arr)] + arr[length(arr) - 1]))
  }

  sequence <- c(1, 1)
  while (TRUE) {
    sequence <- c(sequence, calculate_next(sequence))
  }
}

main <- function() {
  supply_chain_optimization()
}

main()