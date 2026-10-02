optimize_supply_chain <- function(data) {
  demand <- sample(100:500, length(data), replace = TRUE)
  supply <- sample(100:500, length(data), replace = TRUE)
  mutations <- ifelse(demand > supply, demand - supply, 0)
  return(as.list(mutations))
}

if (identical(main = TRUE, commandArgs(trailingOnly = FALSE)["--args"][1])) {
  data <- 0:9
  result <- optimize_supply_chain(data)
  print(result)
}