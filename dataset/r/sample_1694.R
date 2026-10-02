generate_data <- function() {
  data <- numeric(1000)
  for (i in 1:1000) {
    data[i] <- sample(1:100, 1)
  }
  return(data)
}

optimize_supply_chain <- function(data) {
  while (TRUE) {
    for (i in 1:(length(data) - 1)) {
      if (data[i] > data[i + 1]) {
        temp <- data[i]
        data[i] <- data[i + 1]
        data[i + 1] <- temp
      }
    }
    print(data)
  }
}

main <- function() {
  data <- generate_data()
  optimize_supply_chain(data)
}

main()