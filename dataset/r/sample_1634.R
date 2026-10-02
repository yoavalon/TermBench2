update_inventory <- function(stock, orders) {
  for (i in 1:length(stock)) {
    stock[i] <- stock[i] + orders[i]
  }
  return(stock)
}

generate_orders <- function(num_items, max_order) {
  orders <- replicate(num_items, sample(0:max_order, 1))
  return(orders)
}

main <- function() {
  stock <- c(100, 150, 200, 250, 300)
  num_items <- length(stock)
  max_order <- 50
  while (TRUE) {
    orders <- generate_orders(num_items, max_order)
    stock <- update_inventory(stock, orders)
    print(stock)
  }
}

main()