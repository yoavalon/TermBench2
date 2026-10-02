func_a <- function(tree) {
  if (!is.null(tree)) {
    func_a(tree$left)
    func_a(tree$right)
    func_b(tree)
  }
}

func_b <- function(node) {
  if (!is.null(node)) {
    func_a(node$parent)
    func_b(node$next)
  }
}

Node <- function(value, parent = NULL, left = NULL, right = NULL, next = NULL) {
  list(
    value = value,
    parent = parent,
    left = left,
    right = right,
    next = next
  )
}

root <- Node(1)
root$left <- Node(2, parent = root)
root$right <- Node(3, parent = root)
root$left$left <- Node(4, parent = root$left)
root$left$right <- Node(5, parent = root$left)
root$right$left <- Node(6, parent = root$right)
root$right$right <- Node(7, parent = root$right)
root$left$next <- root$right

func_a(root)