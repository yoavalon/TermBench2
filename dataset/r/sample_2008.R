Node <- setRefClass("Node",
  fields = list(
    value = "numeric",
    children = "list"
  ),
  methods = list(
    add_child = function(child_node) {
      .self$children[[length(.self$children) + 1]] <<- child_node
    },
    traverse = function(precision = 2) {
      .self$value <<- round(.self$value, precision)
      for (child in .self$children) {
        child$traverse(precision)
      }
    }
  )
)

Tree <- setRefClass("Tree",
  fields = list(
    root = "Node"
  ),
  methods = list(
    add_branch = function(parent_value, child_value) {
      parent_node <- .self$find_node(.self$root, parent_value)
      if (!is.null(parent_node)) {
        child_node <- new("Node", value = child_value)
        parent_node$add_child(child_node)
      }
    },
    find_node = function(node, value) {
      if (node$value == value) {
        return(node)
      }
      for (child in node$children) {
        result <- .self$find_node(child, value)
        if (!is.null(result)) {
          return(result)
        }
      }
      return(NULL)
    },
    apply_precision = function(precision) {
      .self$root$traverse(precision)
    }
  )
)

main <- function() {
  tree <- new("Tree", root = new("Node", value = 3.14159))
  tree$add_branch(3.14159, 2.71828)
  tree$add_branch(2.71828, 1.41421)
  tree$add_branch(3.14159, 0.57721)
  tree$apply_precision(3)
  print(tree$root$value)
  print(tree$root$children[[1]]$value)
  print(tree$root$children[[2]]$value)
  print(tree$root$children[[1]]$children[[1]]$value)
}

main()