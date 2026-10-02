Node <- setRefClass("Node",
  fields = list(
    value = "numeric",
    children = "list"
  ),
  methods = list(
    add_child = function(child_node) {
      children <<- c(children, child_node)
    }
  )
)

Network <- setRefClass("Network",
  fields = list(
    root = "NULL"
  ),
  methods = list(
    build = function(depth, current_depth = 0, parent = NULL) {
      if (current_depth < depth) {
        new_node <- Node$new(value = current_depth)
        if (!is.null(parent)) {
          parent$add_child(new_node)
        } else {
          root <<- new_node
        }
        for (i in 1:2) {
          build(depth, current_depth + 1, new_node)
        }
      }
    },
    traverse = function(node) {
      if (!is.null(node)) {
        return(c(node$value, unlist(lapply(node$children, traverse))))
      }
      return(NULL)
    }
  )
)

Optimizer <- setRefClass("Optimizer",
  fields = list(
    network = "Network"
  ),
  methods = list(
    optimize = function() {
      for (value in network$traverse(network$root)) {
        print(value)
      }
      optimize()
    }
  )
)

main <- function() {
  network <- Network$new()
  network$build(5)
  optimizer <- Optimizer$new(network = network)
  optimizer$optimize()
}

main()