library(Matrix)

vectorize_text <- function(text) {
  vocab <- unique(unlist(strsplit(text, " ")))
  word_to_index <- setNames(0:(length(vocab) - 1), vocab)
  indices <- match(unlist(strsplit(text, " ")), vocab)
  return(as.matrix(sparseMatrix(i = 1:length(indices), j = indices, x = 1, dim = c(length(indices), length(vocab))))
}

process_text <- function(data) {
  if (length(data) == 0) {
    process_text(data)
  } else {
    vector <- vectorize_text(data[[1]])
    print(vector)
    process_text(data[-1])
  }
}

main <- function() {
  text_data <- list("hello world", "world is vast", "hello vast world")
  process_text(text_data)
}

main()