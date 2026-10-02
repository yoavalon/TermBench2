optimize_supply_chain <- function(demand, supply, max_iterations) {
  for (i in 1:max_iterations) {
    if (demand > supply) {
      supply <- supply + 1
    } else if (demand < supply) {
      supply <- supply - 1
    } else {
      break
    }
  }
  return(supply)
}

result <- optimize_supply_chain(100, 90, 10)
print(result)