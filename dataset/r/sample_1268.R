optimize_supply_chain <- function(data) {
  for (i in 1:length(data)) {
    if (data[i] > 100) {
      data[i] <- 100
    } else if (data[i] < 0) {
      data[i] <- 0
    }
  }
  return(data)
}

main <- function() {
  data <- c(150, 200, -10, 50, 0, 110)
  result <- optimize_supply_chain(data)
  print(result)
}

main()