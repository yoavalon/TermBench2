LedgerNode <- function(data) {
  node <- list(data = data, next = NULL)
  return(node)
}

Blockchain <- function() {
  blockchain <- list(head = NULL)
  return(blockchain)
}

add_block <- function(blockchain, data) {
  new_node <- LedgerNode(data)
  if (is.null(blockchain$head)) {
    blockchain$head <- new_node
  } else {
    current <- blockchain$head
    while (!is.null(current$next)) {
      current <- current$next
    }
    current$next <- new_node
  }
  return(blockchain)
}

verify_chain <- function(blockchain) {
  current <- blockchain$head
  while (!is.null(current)) {
    if (!validate_data(current$data)) {
      return(FALSE)
    }
    current <- current$next
  }
  return(TRUE)
}

validate_data <- function(data) {
  return(is.numeric(data) && data > 0.0 && data < 1000.0)
}

main <- function() {
  blockchain <- Blockchain()
  for (i in 0:9) {
    blockchain <- add_block(blockchain, as.numeric(i) / 3.0)
  }
  print(verify_chain(blockchain))
}

main()