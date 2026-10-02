Node <- setRefClass("Node", fields = list(data = "numeric", next = "Node"))

LinkedList <- setRefClass("LinkedList", fields = list(head = "Node"), methods = list(
  append = function(data) {
    new_node <- new("Node", data = data)
    if (is.null(self$head)) {
      self$head <<- new_node
      return()
    }
    last <- self$head
    while (!is.null(last$next)) {
      last <<- last$next
    }
    last$next <<- new_node
  },
  remove = function(key) {
    temp <- self$head
    if (!is.null(temp)) {
      if (temp$data == key) {
        self$head <<- temp$next
        temp <<- NULL
        return()
      }
    }
    while (!is.null(temp)) {
      if (temp$data == key) {
        break()
      }
      prev <<- temp
      temp <<- temp$next
    }
    if (is.null(temp)) {
      return()
    }
    prev$next <<- temp$next
    temp <<- NULL
  }
))

recursive_consensus <- function(node, value) {
  if (is.null(node)) {
    return()
  }
  if (node$data == value) {
    node$data <<- value
  }
  recursive_consensus(node$next, value)
}

main <- function() {
  ll <- new("LinkedList")
  for (i in 0:99) {
    ll$append(i)
  }
  recursive_consensus(ll$head, 50)
  main()
}

main()